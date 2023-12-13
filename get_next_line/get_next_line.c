/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:36:49 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/12/12 16:20:58 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
}

int	cut_line(char **buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] != '\n')
	{
		free_buffer(buffer);
		return (0);
	}
	tmp = malloc(ft_strlen(*buffer) - i + 1);
	if (!tmp)
		return (-1);
	j = 0;
	i++;
	while ((*buffer)[i])
		tmp[j++] = (*buffer)[i++];
	tmp[j] = '\0';
	free_buffer(buffer);
	*buffer = tmp;
	return (0);
}

int	extract_line(char **buffer, char **line)
{
	int	i;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if ((*buffer)[i] == '\n')
		i++;
	*line = ft_substr(*buffer, 0, i);
	if (!(*line))
		return (-1);
	return (0);
}

int	put_in_buff(int fd, char **buffer)
{
	char	*temp;
	char	*new_buffer;
	ssize_t	read_status;

	read_status = 1;
	while (read_status > 0)
	{
		temp = malloc(BUFFER_SIZE + 1);
		if (!temp)
			return (-1);
		read_status = read(fd, temp, BUFFER_SIZE);
		if (read_status == -1 || (!read_status && !(*buffer)))
			return (free(temp), -1);
		temp[read_status] = '\0';
		new_buffer = ft_strjoin(*buffer, temp);
		free(temp);
		if (!new_buffer)
			return (-1);
		free_buffer(buffer);
		*buffer = new_buffer;
		if (ft_strchr(*buffer, '\n'))
			break ;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
	{
		free_buffer(&buffer);
		return (NULL);
	}
	if (put_in_buff(fd, &buffer) == -1)
	{
		free_buffer(&buffer);
		return (NULL);
	}
	if (extract_line(&buffer, &line) == -1)
	{
		free_buffer(&buffer);
		return (NULL);
	}
	if (cut_line(&buffer) == -1)
	{
		free_buffer(&buffer);
		free(line);
		return (NULL);
	}
	return (line);
}

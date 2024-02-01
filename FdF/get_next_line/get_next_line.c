/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:36:49 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/08 14:57:24 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_buffer(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
}

static int	cut_line(char **buffer)
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

static int	extract_line(char **buffer, char **line)
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

static int	put_in_buff(int fd, char **buffer)
{
	char	*tmp;
	char	*new_buff;
	ssize_t	readed;

	readed = 1;
	while (readed > 0)
	{
		tmp = malloc(BUFFER_SIZE + 1);
		if (!tmp)
			return (-1);
		readed = read(fd, tmp, BUFFER_SIZE);
		if (readed == -1 || (!readed && !(*buffer)))
			return (free(tmp), -1);
		tmp[readed] = '\0';
		new_buff = ft_strjoin(*buffer, tmp);
		free(tmp);
		if (!new_buff)
			return (-1);
		free_buffer(buffer);
		*buffer = new_buff;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:36:49 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/11/28 15:04:21 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *buff)
{
	int		i;
	int		len;
	char	*line;
	size_t	check;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	len = i;
	if (buff[i] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	check = ft_strlcpy(line, buff, len);
	if (check <= 0)
		return (NULL);
	line[len] = '\0';
	ft_memmove(buff, buff + len, ft_strlen(buff) - len + 1);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE+ 1];
	char		*str;
	ssize_t		readed;

	if (!fd)
		return (NULL);
	readed = read(fd, buffer, sizeof(char) * (BUFFER_SIZE - 1));
	if (readed <= 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	str = extract_line(buffer);
	return (str);
}

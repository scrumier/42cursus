/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_net_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:20:49 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/11/23 12:16:54 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_to_static_buffer(int fd, char **static_buf)
{
	char	buf[BUFFER_SIZE + 1];
	int		rd;

	rd = read(fd, buf, BUFFER_SIZE);
	while (rd > 0)
	{
		buf[rd] = '\0';
		*static_buf = append_char(*static_buf, buf);
		if (!*static_buf)
			return (-1);
		if (find_newline(*static_buf) >= 0)
			return (1);
		rd = read(fd, buf, BUFFER_SIZE);
	}
	return (rd);
}

static char	*extract_line_from_buffer(char **static_buf)
{
	char	*line;
	int		newline_index;

	newline_index = find_newline(*static_buf);
	if (newline_index >= 0)
	{
		line = extract_line(*static_buf, newline_index);
		*static_buf = update_static_buffer(*static_buf, newline_index + 1);
		return (line);
	}
	else if (*static_buf && **static_buf)
	{
		line = extract_last_line(static_buf);
		return (line);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*static_buf;
	int			result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	result = read_to_static_buffer(fd, &static_buf);
	if (result == -1)
		return (NULL);

	return (extract_line_from_buffer(&static_buf));
}

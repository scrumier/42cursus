/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:35:36 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/11/21 10:28:36 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buff_tmp;
	char		*buff;
	char		*ligne;
	ssize_t		readed;

	buff_tmp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readed = read(fd, buff, BUFFER_SIZE);
	if (readed <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[readed] = '\0';
	while (readed > 0)
	{
		ligne[readed] = buff;
	}
	free(buff);
	return (ligne);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/06 12:03:54 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return (-1);
	if (!(write(fd, &(*s), ft_strlen(s))))
		return (-1);
	return (0);
}

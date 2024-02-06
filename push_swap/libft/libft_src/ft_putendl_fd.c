/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:22 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/06 12:03:44 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (-1);
	if (!(ft_putstr_fd(s, fd) == 1))
		return (-1);
	if (!(ft_putchar_fd('\n', fd) == 1))
		return (-1);
	return (0);
}

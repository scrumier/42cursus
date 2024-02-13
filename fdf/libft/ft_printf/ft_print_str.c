/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:17:13 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/13 14:24:04 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	while (*str)
	{
		if (ft_print_char(*str++) < 0)
			return (-1);
		count++;
	}
	return (count);
}

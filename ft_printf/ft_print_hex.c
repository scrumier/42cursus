/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:32:27 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/11/21 11:09:04 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

static int	ft_puthex_recursive(unsigned int num, const char *base, int *count)
{
	if (num >= 16)
	{
		if (ft_puthex_recursive(num / 16, base, count) < 0)
			return (-1);
	}
	if (ft_putchar(base[num % 16]) < 0)
		return (-1);
	(*count)++;
	return (1);
}

int	ft_print_hex(unsigned int num, char format)
{
	int	count;

	count = 0;
	if (format == 'x')
	{
		if (ft_puthex_recursive(num, "0123456789abcdef", &count) < 0)
			return (-1);
	}
	else if (format == 'X')
	{
		if (ft_puthex_recursive(num, "0123456789ABCDEF", &count) < 0)
			return (-1);
	}
	return (count);
}

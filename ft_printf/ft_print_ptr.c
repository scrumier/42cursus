/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:25:06 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/12/13 12:54:11 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex(unsigned long num)
{
	int	count;
	int	tmp;

	count = 0;
	if (num >= 16)
	{
		count += ft_puthex(num / 16);
	}
	tmp = ft_print_char("0123456789abcdef"[num % 16]);
	if (tmp < 0)
		return (-1);
	count += tmp;
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long	addr;
	int				count;
	int				tmp;

	count = 0;
	addr = (unsigned long)ptr;
	if (!ptr)
	{
		if (write(1, "0x0", 3) < 0)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) < 0)
		return (-1);
	count += 2;
	tmp = ft_puthex(addr);
	if (tmp < 0)
		return (-1);
	count += tmp;
	return (count);
}

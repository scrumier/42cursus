/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:11:51 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/11/21 11:57:21 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) < 0)
			return (-1);
		count += 11;
		return (count);
	}
	if (n < 0)
	{
		if (ft_print_char('-') < 0)
			return (-1);
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += ft_print_int(n / 10);
	}
	if (ft_print_char(n % 10 + '0') < 0)
		return (-1);
	count++;
	return (count);
}

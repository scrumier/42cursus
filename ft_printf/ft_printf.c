/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:42:13 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/11/22 13:51:07 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);
	return (1);
}

static int	format_specifier(va_list *args, char format)
{
	int	count;

	if (format == 'd' || format == 'i')
		count = (ft_print_int(va_arg(*args, int)));
	else if (format == 'u')
		count = (ft_print_uint(va_arg(*args, unsigned int)));
	else if (format == 's')
		count = (ft_print_str(va_arg(*args, char *)));
	else if (format == 'c')
		count = (ft_print_char(va_arg(*args, int)));
	else if (format == 'p')
		count = (ft_print_ptr(va_arg(*args, void *)));
	else if (format == 'x' || format == 'X')
		count = (ft_print_hex(va_arg(*args, unsigned int), format));
	else if (format == '%')
		count = (ft_print_char('%'));
	else
		count = (-1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		tmp;
	va_list	args;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			tmp = format_specifier(&args, *format);
			if (tmp < 0)
				return (-1);
			count += tmp;
		}
		else if (ft_print_char(*format) < 0)
			return (-1);
		else
			count++;
		format++;
	}
	va_end(args);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:59:39 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/11/21 11:57:51 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_print_hex(unsigned int num, char format);
int		ft_print_int(int n);
int		ft_print_ptr(void *ptr);
int		ft_print_str(char *str);
int		ft_print_uint(unsigned int num);
int		ft_print_char(char c);
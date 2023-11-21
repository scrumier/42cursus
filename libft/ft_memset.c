/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:15 by scrumier          #+#    #+#             */
/*   Updated: 2023/11/16 13:09:40 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	fill;
	int				i;

	str = s;
	fill = c;
	i = 0;
	while (n > 0)
	{
		str[i] = fill;
		i++;
		n--;
	}
	return (s);
}

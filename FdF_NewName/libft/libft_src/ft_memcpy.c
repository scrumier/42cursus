/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:06 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/13 14:19:34 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;

	if (!dest && !src)
		return (0);
	dst = (char *)dest;
	source = (const char *)src;
	while (n > 0)
	{
		*dst++ = *source++;
		n--;
	}
	return (dest);
}

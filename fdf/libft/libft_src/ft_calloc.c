/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:31:58 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/14 14:40:56 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*target;
	size_t	max;

	max = (size_t) - 1;
	if (size == 0 || nmemb == 0)
	{
		target = malloc(0);
		if (target == NULL)
			return (NULL);
		return (target);
	}
	else if (nmemb >= max / size)
		return (NULL);
	else
		target = malloc(nmemb * size);
	if (target == NULL)
		return (NULL);
	ft_bzero(target, nmemb * size - 1);
	return (target);
}

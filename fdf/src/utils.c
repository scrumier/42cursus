/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:25:59 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/11 12:45:22 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_isnumber(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_countwords(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != ' ')
		{
			count++;
			while (s[i] && s[i] != ' ')
				i++;
		}
		else
			i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:33:00 by scrumier          #+#    #+#             */
/*   Updated: 2024/01/16 11:29:45 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list **lst)
{
	int	i;

	i = 0;
	if (!*lst)
	{
		return (0);
	}
	if (!(*lst)->next)
	{
		return (1);
	}
	while (*lst)
	{
		(*lst) = (*lst)->next;
		i++;
	}
	return (i);
}

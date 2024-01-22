/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_sort_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:11:19 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/18 12:17:13 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	checkdup(t_list *list_a)
{
	t_list	*tmp;

	while (list_a)
	{
		tmp = list_a->next;
		while (tmp)
		{
			if (list_a->value == tmp->value)
				return (-1);
			tmp = tmp->next;
		}
		list_a = list_a->next;
	}
	return (0);
}

int	ft_checksorted(t_list *list_a)
{
	int	prev;

	if (!list_a)
		return (0);
	prev = list_a->value;
	while (list_a)
	{
		if (prev > list_a->value)
			return (0);
		prev = list_a->value;
		list_a = list_a->next;
	}
	return (1);
}

int	ft_rev_checksorted(t_list *list_b)
{
	int	prev;

	prev = list_b->value;
	while (list_b)
	{
		if (prev < list_b->value)
			return (0);
		prev = list_b->value;
		list_b = list_b->next;
	}
	return (1);
}
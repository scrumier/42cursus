/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:44:25 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/15 13:26:56 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	needed_bits(t_list **list)
{
	int		max;
	int		max_bits;
	t_list	*head;

	max_bits = 0;
	head = *list;
	max = head->index;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_by_bit(t_list **list_a, t_list **list_b, int size, int bit)
{
	int		j;
	t_list	*head_a;

	j = 0;
	while (j++ < size)
	{
		head_a = *list_a;
		if (((head_a->index >> bit) & 1) == 1)
			ra(list_a, list_b);
		else
			pb(list_a, list_b);
		if (is_sorted(list_a))
			break ;
	}
}

void	radix_sort(t_list **list_a, t_list **list_b)
{
	int		i;
	int		size;
	int		bits;
	t_list	*head_a;

	i = 0;
	head_a = *list_a;
	size = ft_lstsize(head_a);
	bits = needed_bits(list_a);
	while (i < bits)
	{
		sort_by_bit(list_a, list_b, size, i);
		while (ft_lstsize(*list_b) != 0)
			pa(list_a, list_b);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:44:25 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/06 11:34:45 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	needed_bits(t_list **stack)
{
	int		max;
	int		max_bits;
	t_list	*head;

	max_bits = 0;
	head = *stack;
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

void	sort_by_bit(t_list **stack_a, t_list **stack_b, int size, int bit)
{
	int		j;
	t_list	*head_a;

	j = 0;
	while (j++ < size)
	{
		head_a = *stack_a;
		if (((head_a->index >> bit) & 1) == 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		if (is_sorted(stack_a))
			break ;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		size;
	int		bits;
	t_list	*head_a;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	bits = needed_bits(stack_a);
	while (i < bits)
	{
		sort_by_bit(stack_a, stack_b, size, i);
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

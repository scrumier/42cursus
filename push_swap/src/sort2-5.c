/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2-5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:45:02 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/06 11:36:04 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min(t_list **stack, int val)
{
	t_list	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	calculate_min_values(t_list **stack_a, int *min, int *next_min)
{
	*min = get_min(stack_a, -1);
	*next_min = get_min(stack_a, *min);
}

void	sort_logic(t_list **stack_a, t_list *head, int min, int next_min)
{
	if (head->index == min && head->next->index != next_min)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
		{
			sa(stack_a);
			rra(stack_a);
		}
	}
}

void	sort_3(t_list **stack_a)
{
	int		min;
	int		next_min;
	t_list	*head;

	head = *stack_a;
	calculate_min_values(stack_a, &min, &next_min);
	if (!is_sorted(stack_a))
		sort_logic(stack_a, head, min, next_min);
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	if (is_sorted(stack_a))
		return ;
	distance = get_distance(stack_a, get_min(stack_a, -1));
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

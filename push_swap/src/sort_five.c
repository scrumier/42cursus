/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2-5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:45:02 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/15 13:27:00 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_min(t_list **list, int val)
{
	t_list	*head;
	int		min;

	head = *list;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != val)
			min = head->index;
	}
	return (min);
}

void	calculate_min_values(t_list **list_a, int *min, int *next_min)
{
	*min = get_min(list_a, -1);
	*next_min = get_min(list_a, *min);
}

void	sort_logic(t_list **list_a, t_list **list_b, int min, int next_min)
{
	t_list	*head;

	head = *list_a;
	if (head->index == min && head->next->index != next_min)
	{
		make_ra_sa_rra(list_a, list_b);
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(list_a, list_b);
		else
			rra(list_a, list_b);
	}
	else
	{
		if (head->next->index == min)
			ra(list_a, list_b);
		else
		{
			sa(list_a, list_b);
			rra(list_a, list_b);
		}
	}
}

void	sort_3(t_list **list_a, t_list **list_b)
{
	int		min;
	int		next_min;

	calculate_min_values(list_a, &min, &next_min);
	if (!is_sorted(list_a))
		sort_logic(list_a, list_b, min, next_min);
}

void	sort_4(t_list **list_a, t_list **list_b)
{
	int	distance;

	if (is_sorted(list_a))
		return ;
	distance = get_distance(list_a, get_min(list_a, -1));
	if (distance == 1)
		ra(list_a, list_b);
	else if (distance == 2)
	{
		ra(list_a, list_b);
		ra(list_a, list_b);
	}
	else if (distance == 3)
		rra(list_a, list_b);
	if (is_sorted(list_a))
		return ;
	pb(list_a, list_b);
	sort_3(list_a, list_b);
	pa(list_a, list_b);
}

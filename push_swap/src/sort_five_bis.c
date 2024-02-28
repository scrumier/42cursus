/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2-5_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:02:01 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/15 13:25:36 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_5(t_list **list_a, t_list **list_b)
{
	int	distance;

	distance = get_distance(list_a, get_min(list_a, -1));
	if (distance == 1)
		ra(list_a, list_b);
	else if (distance == 2)
	{
		ra(list_a, list_b);
		ra(list_a, list_b);
	}
	else if (distance == 3)
	{
		rra(list_a, list_b);
		rra(list_a, list_b);
	}
	else if (distance == 4)
		rra(list_a, list_b);
	if (is_sorted(list_a))
		return ;
	pb(list_a, list_b);
	sort_4(list_a, list_b);
	pa(list_a, list_b);
}

void	simple_sort(t_list **list_a, t_list **list_b)
{
	int	size;

	if (is_sorted(list_a) || ft_lstsize(*list_a) == 0
		|| ft_lstsize(*list_a) == 1)
		return ;
	size = ft_lstsize(*list_a);
	if (size == 2)
		sa(list_a, list_b);
	else if (size == 3)
		sort_3(list_a, list_b);
	else if (size == 4)
		sort_4(list_a, list_b);
	else if (size == 5)
		sort_5(list_a, list_b);
}

void	make_ra_sa_rra(t_list **list_a, t_list **list_b)
{
	ra(list_a, list_b);
	sa(list_a, list_b);
	rra(list_a, list_b);
}

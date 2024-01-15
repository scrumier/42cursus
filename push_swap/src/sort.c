/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:33:27 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/11 16:21:48 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_min_a(t_list_move **move, t_list **list_a)
{
	if ((*list_a)->index < (ft_lstsize(*list_a) / 2))
	{
		(*move)->ra = ((*list_a)->index);
		return ((*move)->ra);
	}
	else
	{
		(*move)->rra = ft_lstsize(*list_a) - ((*list_a)->index);
		return ((*move)->rra);
	}
}

int find_min_b(t_list_move **move, t_list **list_b)
{
    t_list  *current;
    t_list  *previous;
    int     list_size;
    int     half_size;

    if (list_b == NULL || *list_b == NULL || (*list_b)->next == NULL)
        return (0);
    previous = *list_b;
    current = (*list_b)->next;
    list_size = ft_lstsize(*list_b);
    half_size = list_size / 2;
    while (current != NULL)
    {
        if (previous->value < current->value &&
            (current->next == NULL || current->value < current->next->value))
        {
            if (current->index > half_size)
                return (list_size - current->index);
            else
                return (current->index);
        }
        previous = current;
        current = current->next;
    }
    return (0);
}

int		find_next_min(t_list_move **move, t_list **list_a, t_list **list_b)
{
	int	min;

	min = find_min_a(move, list_a);
	min += find_min_b(move, list_b);
	return (min);
}

void	find_best_way(t_list_move **move, t_list **list_a, t_list **list_b)
{
	unsigned int	min;
	unsigned int	next_min;
	t_list_move		*move_tmp;

	min = ft_lstsize(*list_a);
	next_min = 0;
	while((*list_a)->next)
	{
		while (min > next_min)
		{
			next_min = find_next_min(&move_tmp, list_a, list_b);
		}
		*list_a = (*list_a)->next;
	}
	*move = move_tmp;
}

void	sort_best_way2(t_list_move **move, t_list **list_a, t_list **list_b)
{
	while ((*move)->rra)
	{
		rra(list_a, 0);
		(*move)->rra--;
	}
	while ((*move)->rrb)
	{
		rrb(list_b, 0);
		(*move)->rrb--;
	}
	pa(list_a, list_b);
}

void	sort_best_way(t_list_move **move, t_list **list_a, t_list **list_b)
{
	while ((*move)->ra && (*move)->rb)
	{
		rr(list_a, list_b);
		(*move)->ra--;
		(*move)->rb--;
	}
	while ((*move)->rra && (*move)->rrb)
	{
		rrr(list_a, list_b);
		(*move)->rra--;
		(*move)->rrb--;
	}
	while ((*move)->ra)
	{
		ra(list_a, 0);
		(*move)->ra--; 
	}
	while ((*move)->rb)
	{
		rb(list_b, 0);
		(*move)->rb--;
	}
	sort_best_way2(move, list_a, list_b);
}

void	sort(t_list **list_a)
{
	t_list		*list_b;
	t_list_move	*move;
	int			i;

	list_b = NULL;
	move = NULL;
	if (ft_lstsize(*list_a) == 2)
		sa(list_a, 0);
	else
	{
		move = malloc(sizeof(t_list_move));
        if (!move)
            return;
        while (ft_rev_checksorted(list_b) == 0)
        {
            find_best_way(&move, list_a, &list_b);
            sort_best_way(&move, list_a, &list_b);
        }
        free(move); 
	}
	while (pb(list_a, &list_b) != -1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:33:27 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/16 12:11:27 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_min_a(t_list_move **move, t_list **list_a)
{
	if ((*list_a)->index < (ft_lstsize(list_a) / 2))
	{
		(*move)->ra = ((*list_a)->index);
		(*move)->rra = 0;
		return ((*move)->ra);
	}
	else
	{ 
		(*move)->rra = ft_lstsize(list_a) - ((*list_a)->index);
		(*move)->ra = 0;
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
    list_size = ft_lstsize(list_b);
    half_size = list_size / 2;
    while (current != NULL)
    {
        if (previous->value < current->value &&
            (current->next == NULL || current->value < current->next->value))
        {
            if (current->index > half_size)
			{
                (*move)->rrb = list_size - current->index;
				(*move)->rb = 0;
			}
            else
			{
                (*move)->rb = (current->index);
				(*move)->rrb = 0;
			}
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

	min = ft_lstsize(list_a);
	next_min = 0;
	while (*list_a)
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
	write(1, "p", 1);
		rra(list_a, 0);
		(*move)->rra--;
	}
	while ((*move)->rrb)
	{
	write(1, "q", 1);
		rrb(list_b, 0);
		(*move)->rrb--;
	}
	write(1, "r", 1);
	pa(list_a, list_b);
}

void	sort_best_way(t_list_move **move, t_list **list_a, t_list **list_b)
{
	while ((*move)->ra && (*move)->rb)
	{
	write(1, "l", 1);
		rr(list_a, list_b);
		(*move)->ra--;
		(*move)->rb--;
	}
	while ((*move)->rra && (*move)->rrb)
	{
		write(1, "m", 1);

		rrr(list_a, list_b);
		(*move)->rra--;
		(*move)->rrb--;
	}
	while ((*move)->ra)
	{
	write(1, "n", 1);
		ra(list_a, 0);
		(*move)->ra--; 
	}
	while ((*move)->rb)
	{
	write(1, "o", 1);
		rb(list_b, 0);
		(*move)->rb--;
	}
	sort_best_way2(move, list_a, list_b);
}

void	sort(t_list **list_a)
{
	t_list		*list_b;
	t_list		*head_a;
	t_list		*head_b;
	t_list_move	*move;
	int			i;

	list_b = NULL;
	move = NULL;
	head_a = *list_a;
	head_b = list_b;
	if (ft_lstsize(list_a) == 2)
	{
		sa(list_a, 0);
		return ;
	}
	else
	{
		*list_a = head_a;
		if (!(*list_a))
			write(1, "z", 1);
		*list_a = head_a;
        while (*list_a)
        {
			write(1, "a", 1);
			*list_a = head_a;
			put_index(list_a, &list_b);
			write(1, "b", 1);
			*list_a = head_a;
            find_best_way(&move, list_a, &list_b);
			write(1, "c", 1);
			*list_a = head_a;
            sort_best_way(&move, list_a, &list_b);
			write(1, "d", 1);
        }
        free(move); 
	}
	while (pb(list_a, &list_b) != -1);
}

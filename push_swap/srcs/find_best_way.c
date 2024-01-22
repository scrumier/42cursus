/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_way.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:57:19 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/19 20:19:34 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_min_a(t_list_move **move, t_list *list_a, t_list *list_b)
{
	int result;

	if (!move || !list_a || !list_b)
		write(1, "ERROR\n", 6);
	(void)list_b;
	if (list_a->index >= ft_lstsize(list_a) / 2)
	{
		(*move)->ra = list_a->index - 1;
		result = (*move)->ra;
		return (result);
	}
	else
	{
		(*move)->rra = list_a->index - (ft_lstsize(list_a) / 2);
		result = (*move)->rra;
		return (result);
	}
}

int	is_new_max(t_list *list_b, int i)
{
	t_list	*tmp;

	tmp = list_b;
	while (tmp)
	{
		if (tmp->value > i)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

int	is_new_min(t_list *list_b, int i)
{
	t_list	*tmp;

	tmp = list_b;
	while (tmp)
	{
		if (tmp->value < i)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (0);
}

int find_min_b(t_list_move **move, t_list *list_a, t_list *list_b)
{
	int result;
	t_list	*tmp_b;

	tmp_b = list_b;
	if (!move || !list_a || !list_b)
		write(1, "ERROR\n", 6);
	if (is_new_max(list_b, list_a->value) == 0)
	{
		if (list_b->index >= ft_lstsize(list_b) / 2)
		{
			(*move)->rb = is_new_max(list_b, list_a->value);
			result = (*move)->rb;
			return (result);
		}
		else
		{
			(*move)->rrb = is_new_max(list_b, list_a->value) - ft_lstsize(list_b);
			result = (*move)->rrb;
			return (result);
		}
	}
	else if (is_new_min(list_b, list_a->value) == 0)
	{
		if (list_b->index >= ft_lstsize(list_b) / 2)
		{
			(*move)->rb = is_new_min(list_b, list_a->value) - 1;
			result = (*move)->rb;
			return (result);
		}
		else
		{
			(*move)->rrb = is_new_min(list_b, list_a->value) - (ft_lstsize(list_b) / 2);
			result = (*move)->rrb;
			return (result);
		}
	}
	else
	{
		while (tmp_b->next && list_a->value != tmp_b->value + 1 && list_a->value != tmp_b->next->value - 1)
		{
			if (tmp_b->index >= ft_lstsize(list_b) / 2)
			{
				(*move)->rb = tmp_b->index;
				result = (*move)->rb;
				return (result);
			}
			else
			{
				(*move)->rrb = tmp_b->index - (ft_lstsize(list_b) / 2);
				result = (*move)->rrb;
				return (result);
			}
		}
		tmp_b = list_b;
		while (tmp_b->next && list_a->value > tmp_b->value - 1 && list_a->value < tmp_b->next->value + 1)
		{
			if (tmp_b->index >= ft_lstsize(list_b) / 2)
			{
				(*move)->rb = tmp_b->index;
				result = (*move)->rb;
				return (result);
			}
			else
			{
				(*move)->rrb = tmp_b->index - (ft_lstsize(list_b) / 2);
				result = (*move)->rrb;
				return (result);
			}
		}
	}
	return (0);
}

void find_best_way(t_list_move **move, t_list *list_a, t_list *list_b)
{
	t_list	*tmp_a;
	t_list	*tmp_b;
	t_list_move	*move_tmp;
	int		result;
	int		tmp;

	tmp_a = list_a;
	result = 2147483647;
	tmp_b = list_b;
	while (tmp_a)
	{
		move_tmp = malloc(sizeof(t_list_move));
		if (!move_tmp)
			ft_error();
		tmp = find_min_a(&move_tmp, tmp_a, tmp_b);
		tmp += find_min_b(&move_tmp, tmp_a, tmp_b);
		if (tmp < result)
		{
			result = tmp;
			if (!(*move))  // If *move is NULL, allocate memory for it
			{
				*move = malloc(sizeof(t_list_move));
				if (!(*move))
					ft_error();
			}
			// Copy the values from move_tmp to *move
			(*move)->ra = move_tmp->ra;
			(*move)->rb = move_tmp->rb;
			(*move)->rra = move_tmp->rra;
			(*move)->rrb = move_tmp->rrb;
		}
		move_tmp->ra = 0;
		move_tmp->rb = 0;
		move_tmp->rra = 0;
		move_tmp->rrb = 0;
		tmp_a = tmp_a->next;
		free_list_move(move_tmp);
	}
}

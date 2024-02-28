/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:43:44 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/15 14:08:52 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_list **list, t_list **list_a, t_list **list_b)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*list) < 2)
		return (-1);
	head = *list;
	next = head->next;
	if (!head && !next)
		ft_error("Error: list is empty", list_a, list_b);
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **list_a, t_list **list_b)
{
	if (swap(list_a, list_a, list_b) == -1)
		return (-1);
	if (ft_putendl_fd("sa", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

int	sb(t_list **list_a, t_list **list_b)
{
	if (swap(list_b, list_a, list_b) == -1)
		return (-1);
	if (ft_putendl_fd("sb", 1) == -1)
		ft_error("Error", list_b, list_b);
	return (0);
}

int	ss(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_a) < 2) || (ft_lstsize(*list_b) < 2))
		return (-1);
	swap(list_a, list_a, list_b);
	swap(list_b, list_a, list_b);
	if (ft_putendl_fd("ss", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

int	push(t_list **list_to, t_list **list_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*list_from) == 0)
		return (-1);
	head_to = *list_to;
	head_from = *list_from;
	tmp = head_from;
	head_from = head_from->next;
	*list_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*list_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*list_to = tmp;
	}
	return (0);
}

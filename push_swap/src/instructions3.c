/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:39:58 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/15 13:26:48 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rr(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_a) < 2) || (ft_lstsize(*list_b) < 2))
		return (-1);
	rotate(list_a);
	rotate(list_b);
	if (ft_putendl_fd("rr", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

int	reverse_rotate(t_list **list)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*list) < 2)
		return (-1);
	head = *list;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *list;
	*list = tail;
	return (0);
}

int	rra(t_list **list_a, t_list **list_b)
{
	if (reverse_rotate(list_a) == -1)
		return (-1);
	if (ft_putendl_fd("rra", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

int	rrb(t_list **list_a, t_list **list_b)
{
	if (reverse_rotate(list_b) == -1)
		return (-1);
	if (ft_putendl_fd("rrb", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

int	rrr(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_a) < 2) || (ft_lstsize(*list_b) < 2))
		return (-1);
	reverse_rotate(list_a);
	reverse_rotate(list_b);
	if (ft_putendl_fd("rrr", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

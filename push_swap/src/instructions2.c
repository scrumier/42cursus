/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:39:41 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/15 13:26:44 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pa(t_list **list_a, t_list **list_b)
{
	if (push(list_a, list_b) == -1)
		return (-1);
	if (ft_putendl_fd("pa", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

int	pb(t_list **list_a, t_list **list_b)
{
	if (push(list_b, list_a) == -1)
		return (-1);
	if (ft_putendl_fd("pb", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

int	rotate(t_list **list)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*list) < 2)
		return (-1);
	head = *list;
	tail = ft_lstlast(head);
	*list = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **list_a, t_list **list_b)
{
	if (rotate(list_a) == -1)
		return (-1);
	if (ft_putendl_fd("ra", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

int	rb(t_list **list_a, t_list **list_b)
{
	if (rotate(list_b) == -1)
		return (-1);
	if (ft_putendl_fd("rb", 1) == -1)
		ft_error("Error", list_a, list_b);
	return (0);
}

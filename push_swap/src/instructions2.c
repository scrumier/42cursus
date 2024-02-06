/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:39:41 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/06 12:03:31 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == -1)
		return (-1);
	if (ft_putendl_fd("pa", 1) == -1)
		ft_error("Error");
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == -1)
		return (-1);
	if (ft_putendl_fd("pb", 1) == -1)
		ft_error("Error");
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_list **stack_a)
{
	if (rotate(stack_a) == -1)
		return (-1);
	if (ft_putendl_fd("ra", 1) == -1)
		ft_error("Error");
	return (0);
}

int	rb(t_list **stack_b)
{
	if (rotate(stack_b) == -1)
		return (-1);
	if (ft_putendl_fd("rb", 1) == -1)
		ft_error("Error");
	return (0);
}

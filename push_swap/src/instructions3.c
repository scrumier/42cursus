/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:39:58 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/13 12:50:06 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	rr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	rotate(stack_a);
	rotate(stack_b);
	if (ft_putendl_fd("rr", 1) == -1)
		ft_error("Error", stack_a, stack_b);
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
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
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_a) == -1)
		return (-1);
	if (ft_putendl_fd("rra", 1) == -1)
		ft_error("Error", stack_a, stack_b);
	return (0);
}

int	rrb(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rotate(stack_b) == -1)
		return (-1);
	if (ft_putendl_fd("rrb", 1) == -1)
		ft_error("Error", stack_a, stack_b);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (ft_putendl_fd("rrr", 1) == -1) 
		ft_error("Error", stack_a, stack_b);
	return (0);
}

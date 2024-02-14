/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:43:44 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/13 13:01:02 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_list **stack, t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error: stack is empty", stack_a, stack_b);
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a, stack_a, stack_b) == -1)
		return (-1);
	if (ft_putendl_fd("sa", 1) == -1)
		ft_error("Error", stack_a, stack_b);
	return (0);
}

int	sb(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_b, stack_a, stack_b) == -1)
		return (-1);
	if (ft_putendl_fd("sb", 1) == -1)
		ft_error("Error", stack_b, stack_b);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return (-1);
	swap(stack_a, stack_a, stack_b);
	swap(stack_b, stack_a, stack_b);
	if (ft_putendl_fd("ss", 1) == -1)
		ft_error("Error", stack_a, stack_b);
	return (0);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}
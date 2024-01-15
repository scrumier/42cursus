/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:24:22 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/11 16:22:40 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_list **list_a, int j)
{
	t_list	*tmp;

	if ((ft_lstsize(*list_a) < 2))
		return (-1);
	if (!*list_a || !((*list_a)->next))
		return (-1);
	tmp = *list_a;
	*list_a = (*list_a)->next;
	tmp->next = (*list_a)->next;
	(*list_a)->next = tmp;
	if (j == 0)
		ft_putendl_fd("sa\n", 1);
	return (0);
}


int	sb(t_list **list_b, int j)
{
	t_list	*tmp;

	if ((ft_lstsize(*list_b) < 2))
		return (-1);
	if (!*list_b || !((*list_b)->next))
		return (-1);
	tmp = *list_b;
	*list_b = (*list_b)->next;
	tmp->next = (*list_b)->next;
	(*list_b)->next = tmp;
	if (j == 0)
		ft_putendl_fd("sa\n", 1);
	return (0);
}

int	ss(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_b) < 2) || (ft_lstsize(*list_b) < 2))
		return (-1);
	if ((sa(list_a, 1) == -1) || (sb(list_b, 1) == -1))
		return (-1);
	ft_putendl_fd("ss\n", 1);
	return (0);
}

int	pa(t_list **list_a, t_list **list_b)
{
	if (!*list_a || !*list_b)
		return (-1);
	ft_lstadd_front(list_a, *list_b);
	ft_putendl_fd("pa\n", 1);
	return (0);
}

int	pb(t_list **list_a, t_list **list_b)
{
	if (!*list_a || !*list_b)
		return (-1);
	ft_lstadd_front(list_b, *list_a);
	ft_putendl_fd("pb\n", 1);
	return (0);
}

int	ra(t_list **list_a, int i)
{
	t_list  *first;
	t_list  *last;

	if (list_a == NULL || *list_a == NULL || (*list_a)->next == NULL)
		return (-1);
	first = *list_a;
	last = *list_a;
	while (last->next != NULL)
		last = last->next;
	*list_a = first->next;
	first->next = NULL;
	last->next = first;
	if (i == 0)
		ft_putendl_fd("ra\n", 1);
	return (0);
}

int	rb(t_list **list_b, int i)
{
	t_list  *first;
	t_list  *last;

	if (list_b == NULL || *list_b == NULL || (*list_b)->next == NULL)
		return (-1);
	first = *list_b;
	last = *list_b;
	while (last->next != NULL)
		last = last->next;
	*list_b = first->next;
	first->next = NULL;
	last->next = first;
	if (i == 0)
		ft_putendl_fd("rb\n", 1);
	return (0);
}

int	rr(t_list **list_a, t_list **list_b)
{
	if (ra(list_a, 0) == -1)
		return (-1);
	if (rb(list_b, 0) == -1)
		return (-1);
	ft_putendl_fd("rr\n", 1);
	return (0);	
}

int	rra(t_list **list_a, int i)
{
	t_list  *first;
	t_list  *last;

	if (list_a == NULL || *list_a == NULL || (*list_a)->next == NULL)
		return (-1);
	last = *list_a;
	first = *list_a;
	while (first->next != NULL)
		first = first->next;
	*list_a = last->next;
	last->next = NULL;
	first->next = first;
	if (i == 0)
		ft_putendl_fd("rra\n", 1);
	return (0);
}

int	rrb(t_list **list_b, int i)
{
	t_list  *first;
	t_list  *last;

	if (list_b == NULL || *list_b == NULL || (*list_b)->next == NULL)
		return (-1);
	last = *list_b;
	first = *list_b;
	while (first->next != NULL)
		first = first->next;
	*list_b = last->next;
	last->next = NULL;
	first->next = first;
	if (i == 0)
		ft_putendl_fd("rrb\n", 1);
	return (0);
}

int rrr(t_list **list_a, t_list **list_b)
{
	if (rra(list_a, 1) == -1)
		return (-1);
	if (rrb(list_b, 1) == -1)
		return (-1);
	ft_putendl_fd("rrr\n", 1);
	return (0);	
}
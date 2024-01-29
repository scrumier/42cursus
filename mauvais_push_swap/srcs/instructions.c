/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:24:22 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/22 16:24:30 by sonamcrumie      ###   ########.fr       */
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
		ft_putendl_fd("sa", 1);
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
		ft_putendl_fd("sa", 1);
	return (0);
}

int	ss(t_list **list_a, t_list **list_b)
{
	if ((ft_lstsize(*list_b) < 2) || (ft_lstsize(*list_b) < 2))
		return (-1);
	if ((sa(list_a, 1) == -1) || (sb(list_b, 1) == -1))
		return (-1);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	pa(t_list **list_a, t_list **list_b, int j)
{
	t_list	*tmp;
	
	if (!*list_b)
		return (-1);
	tmp = *list_a;
	*list_a = *list_b;
	*list_b = (*list_b)->next;
	(*list_a)->next = tmp;
	if (j == 0)
		ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_list **list_a, t_list **list_b, int j)
{
	t_list	*tmp;

	if (!*list_a)
		return (-1);
	tmp = *list_b;
	*list_b = *list_a;
	*list_a = (*list_a)->next;
	(*list_b)->next = tmp;
	if (j == 0)
		ft_putendl_fd("pb", 1);
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
		ft_putendl_fd("ra", 1);
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
		ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_list **list_a, t_list **list_b)
{
	if (ra(list_a, 1) == -1)
		return (-1);
	if (rb(list_b, 1) == -1)
		return (-1);
	ft_putendl_fd("rr", 1);
	return (0);	
}

void	rra(t_list **list_a, int j)
{
	t_list	*tmp;
	int		i;

	if (!*list_a || !(*list_a)->next)
		return ;
	i = 0;
	tmp = *list_a;
	while ((*list_a)->next)
	{
		*list_a = (*list_a)->next;
		i++;
	}
	(*list_a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list **list_b, int j)
{
	t_list	*tmp;
	int		i;

	if (!*list_b || !(*list_b)->next)
		return ;
	i = 0;
	tmp = *list_b;
	while ((*list_b)->next)
	{
		i++;
		*list_b = (*list_b)->next;
	}
	(*list_b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		ft_putendl_fd("rrb", 1);
}

static void	rrr_sub(t_list **b, int j)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while ((*b)->next)
	{
		i++;
		*b = (*b)->next;
	}
	(*b)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	if (j == 0)
		ft_putendl_fd("rrr", 1);
}

void	rrr(t_list **list_a, t_list **list_b, int j)
{
	t_list	*tmp;
	int		i;

	if (!*list_a || !((*list_a)->next) || !*list_b || !((*list_b)->next))
		return ;
	i = 0;
	tmp = *list_a;
	while ((*list_a)->next)
	{
		i++;
		*list_a = (*list_a)->next;
	}
	(*list_a)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
	rrr_sub(list_b, j);
}
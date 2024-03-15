/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:38:03 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/15 13:07:05 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *msg, t_list **a, t_list **b)
{
	if (a && *a)
	{
		free_list(*a);
		free(a);
	}
	if (b && *b)
	{
		free_list(*b);
		free(b);
	}
	ft_putendl_fd(msg, 2);
	exit(EXIT_FAILURE);
}

int	count_nbr(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == '+')
		{
			count++;
			i++;
			while (ft_isdigit(arg[i]))
				i++;
		}
		else
			i++;
	}
	if (count < 2)
		ft_error("", NULL, NULL);
	return (count);
}

int	is_sorted(t_list **list)
{
	t_list	*head;

	head = *list;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	get_distance(t_list **list, int index)
{
	t_list	*head;
	int		distance;

	distance = 0;
	head = *list;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	make_top(t_list **list_a, t_list **list_b, int distance)
{
	t_list	*head;
	int		tmp;

	if (distance == 0)
		return ;
	head = *list_a;
	tmp = ft_lstsize(head) - distance;
	if (distance <= (ft_lstsize(head) / 2))
	{
		while (distance-- > 0)
			ra(list_a, list_b);
	}
	else
	{
		while (tmp-- > 0)
			rra(list_a, list_b);
	}
}

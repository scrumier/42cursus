/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:40:10 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/26 14:07:28 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_double(t_list **list)
{
	t_list	*head;
	t_list	*tmp;

	head = *list;
	while (head)
	{
		tmp = head->next;
		while (tmp)
		{
			if (head->value == tmp->value)
				ft_error("Error", list, NULL);
			tmp = tmp->next;
		}
		head = head->next;
	}
}

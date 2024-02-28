/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:27:35 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/26 14:07:24 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_list(t_list *list)
{
	t_list	*head;
	t_list	*tmp;

	head = list;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	free_all(t_list **list_a, t_list **list_b)
{
	free_list(*list_a);
	free_list(*list_b);
	free(list_a);
	free(list_b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:27:35 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/15 13:07:57 by scrumier         ###   ########.fr       */
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

void ft_error_args(char *str, char **arg)
{
	if (arg)
		ft_free(arg);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
void	free_all(t_list **list_a, t_list **list_b)
{
	free_list(*list_a);
	free_list(*list_b);
	free(list_a);
	free(list_b);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
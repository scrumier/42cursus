/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:46:55 by scrumier          #+#    #+#             */
/*   Updated: 2024/01/15 12:17:37 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int put_index_bis(t_list **list)
{
    int i;

    i = 1;
    while ((*list)->next)
    {
        (*list)->index = i;
        i++;
        *list = (*list)->next;
    }
    (*list)->index = i;
}

int put_index(t_list **list_a, t_list **list_b)
{
    put_index_bis(list_a);
    put_index_bis(list_b);
}
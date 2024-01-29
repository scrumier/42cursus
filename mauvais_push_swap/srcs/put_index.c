/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:46:55 by scrumier          #+#    #+#             */
/*   Updated: 2024/01/18 13:18:31 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void put_index_bis(t_list *list)
{
    int i;
    t_list *current;

    i = 1;
    current = list;
    while (current)
    {
        current->index = i;
        i++;
        current = current->next;
    }
}

void put_index(t_list *list_a, t_list *list_b)
{
    put_index_bis(list_a);
    put_index_bis(list_b);
}

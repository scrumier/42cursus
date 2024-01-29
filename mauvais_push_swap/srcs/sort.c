/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:33:27 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/22 15:48:25 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void sort_best_way2(t_list_move *move, t_list **list_a, t_list **list_b)
{
    while (move->rra > 0)
    {
        rra(list_a, 0);
        move->rra--;
    }
    while (move->rrb > 0)
    {
        rrb(list_b, 0);
        move->rrb--;
    }
    pb(list_a, list_b, 0);
}

void sort_best_way(t_list_move *move, t_list **list_a, t_list **list_b)
{
    while (move->ra > 0 && move->rb > 0)
    {
        rr(list_a, list_b);
        move->ra--;
        move->rb--;
    }
    while (move->rra > 0 && move->rrb > 0)
    {
        rrr(list_a, list_b, 0);
        move->rra--;
        move->rrb--;
    }
    while (move->ra > 0)
    {
        ra(list_a, 0);
        move->ra--;
    }
    while (move->rb > 0)
    {
        rb(list_b, 0);
        move->rb--;
    }
    sort_best_way2(move, list_a, list_b);
}



void sort(t_list **list_a, t_list **list_b)
{
    t_list_move *move;

    if (ft_lstsize(*list_b) == 2)
    {
        sa(list_b, 0);
    }
    else
    {
        pb(list_a, list_b, 0);
        pb(list_a, list_b, 0);
        if (ft_checksorted(*list_b))
            sb(list_b, 0);
        while (*list_a != NULL)
        {
            move = malloc(sizeof(t_list_move));
            if (!move)
                ft_error();

            put_index(*list_a, *list_b);


            find_best_way(&move, *list_a, *list_b);
            printf("After find_best_way :\n");
            print_best_way(move);

            printf("Before sort_best_way :\n");
            print_list(*list_a,*list_b);
            sort_best_way(move, list_a, list_b);

            printf("After sort_best_way :\n");
            print_list(*list_a,*list_b);

            write(1, "\n", 1);
            write(1, "-------------", 13);
            write(1, "\n", 1);
            free_list_move(move);
        }
        while (pa(list_a, list_b, 0) != -1);
    }
}


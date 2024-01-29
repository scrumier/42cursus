/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:42:09 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/22 15:49:16 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void print_best_way(t_list_move *move)
{
    printf("ra: %d\n", move->ra);
    printf("rra: %d\n", move->rra);
    printf("rb: %d\n", move->rb);
    printf("rrb: %d\n", move->rrb);
}

void print_list(t_list *list_a, t_list *list_b)
{
	printf("List :\n");
	while (list_a || list_b)
	{
		if (list_a && list_b)
		{
			printf("%d--", list_a->value);
		}
		if (list_a && !list_b)
		{
			printf("%d--0\n", list_a->value);
			list_a = list_a->next;
		}
		if (list_a && list_b)
		{
			printf("%d\n", list_b->value);
			list_a = list_a->next;
			list_b = list_b->next;
		}
		if (!list_a && list_b)
		{
			printf("0--%d\n", list_b->value);
			list_b = list_b->next;
		}
	}
}

void print_list_with_indices(t_list *list)
{
	while (list)
	{
		printf("Value: %d, Index: %d\n", list->value, list->index);
		list = list->next;
	}
}

int main(int argc, char **argv)
{
	t_list		*list_a;
	t_list		*list_b;

	list_b = NULL;
	if (argc < 2)
		ft_error();
	process(argc, argv, &list_a);
	printf("List contents: \n");
	print_list(list_a, list_b);
	if (!list_a || checkdup(list_a) == -1)
	{
		free_list(&list_a);
		ft_error();
	}

    printf("List contents before sorting:\n");
    print_list(list_a, list_b);

    //while (!ft_checksorted(list_a))
		sort(&list_a, &list_b);

    printf("List contents after sorting:\n");
    print_list(list_a, list_b);

	free_list(&list_a);
	return 0;
}

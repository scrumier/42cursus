/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:42:09 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/16 13:54:47 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_list(t_list *list)
{
    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }
    printf("\n");
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
    t_list *list_a;
	t_list *list_b;

	list_b = NULL;
    if (argc < 2)
        ft_error();
    process(argc, argv, &list_a);
    printf("List contents: ");
    print_list(list_a);
	if (!list_a || checkdup(list_a) == -1)
	{
		free_list(&list_a);
		ft_error();
	}
	if (!ft_checksorted(list_a))
		sort(&list_a);
    while (list_a)
    {
        t_list *temp = list_a;
        list_a = list_a->next;
        free(temp);
    }
    put_index(list_a, &list_b);

    // Print the lists with indices
    printf("List A with indices:\n");
    print_list_with_indices(list_a);

    printf("List B with indices:\n");
    print_list_with_indices(list_b);
    return 0;
}





// int	main(int argc, char **argv)
// {
// 	t_list	*list_a = NULL;

// 	write(1, "u", 1);
// 	list_a = process(argc, argv, &list_a);
// 	if (!list_a || checkdup(list_a) == -1)
// 	{
// 		free_list(&list_a);
// 		ft_error();
// 	}
// 	if (!ft_checksorted(list_a))
// 		sort(&list_a);
// 	free_list(&list_a);
// 	write(1, "hey", 3);
// 	return (0);
// }

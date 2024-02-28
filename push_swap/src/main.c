/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:28:45 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/28 15:54:31 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	parse(t_list **list, int argc, char **argv)
{
	t_list	*new;
	char	**args;
	int		i;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(list, new);
		i++;
	}
	index_list(list);
	if (argc == 2)
		ft_free(args);
}

static void	sort_list(t_list **list_a, t_list **list_b)
{
	if (ft_lstsize(*list_a) <= 5)
		simple_sort(list_a, list_b);
	else
		radix_sort(list_a, list_b);
}

int	main(int argc, char **argv)
{
	t_list	**list_a;
	t_list	**list_b;

	if (argc < 2)
		return (0);
	ft_check_args(argc, argv);
	list_a = (t_list **)malloc(sizeof(t_list));
	list_b = (t_list **)malloc(sizeof(t_list));
	if (!list_a || !list_b)
		ft_error("Error", list_a, list_b);
	*list_a = NULL;
	*list_b = NULL;
	parse(list_a, argc, argv);
	check_double(list_a);
	if (is_sorted(list_a))
	{
		free_all(list_a, list_b);
		return (0);
	}
	sort_list(list_a, list_b);
	free_all(list_a, list_b);
	return (0);
}

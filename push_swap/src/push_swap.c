/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:42:09 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/10 09:42:17 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;

	list_a = process(argc, argv);
	if (!list_a || checkdup(list_a) == -1)
	{
		free_list(&list_a);
		ft_error();
	}
	if (!ft_checksorted(list_a))
		sort(&list_a);
	free_list(&list_a);
	return (0);
}
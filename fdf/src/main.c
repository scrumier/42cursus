/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/23 18:23:30 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_fdf	*data;

	(void)ac;
	data = (t_fdf*)malloc(sizeof(t_fdf));
	fdf_init(*av[1], data);
	int i;
	int j;
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%d ", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}

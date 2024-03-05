/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/05 14:56:13 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static int keys(int key, void *data)
{
	printf("key: %d\n", key);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./fdf file\n", 2);
		return (1);
	}
	data = (t_fdf*)malloc(sizeof(t_fdf));
	fdf_init(av[1], data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "FdF");
	data->zoom = 200;
	draw(data);
	mlx_key_hook(data->win, keys, NULL);
	mlx_loop(data->mlx);
	return (0);
}

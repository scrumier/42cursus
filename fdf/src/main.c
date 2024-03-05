/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/04 13:53:30 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static int keys(int key, void *data)
{
	if (key == 53)
		exit(0);
	if (key == 69)
		((t_fdf*)data)->zoom += 1;
	if (key == 78)
		((t_fdf*)data)->zoom -= 1;
	if (key == 123)
		((t_fdf*)data)->angle -= 0.05;
	if (key == 124)
		((t_fdf*)data)->angle += 0.05;
	mlx_clear_window(((t_fdf*)data)->mlx, ((t_fdf*)data)->win);
	draw((t_fdf*)data);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*data;
	t_coord coords;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./fdf file\n", 2);
		return (1);
	}
	data = (t_fdf*)malloc(sizeof(t_fdf));
	fdf_init(av[1], data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "FdF");
	data->zoom = 20;
	bresenham(coords, data);
	mlx_key_hook(data->win, keys, NULL);
	mlx_loop(data->mlx);
	return (0);
}

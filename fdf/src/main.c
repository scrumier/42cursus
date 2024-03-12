/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/12 16:45:47 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static int keys(int key, t_fdf *data, t_coord coord)
{
	printf("key = %d\n", key);
	if (key == 65307)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free_all(data);
		exit(EXIT_FAILURE);
	}
	else if (key == 61)
	{
		//zoom "="
		((t_fdf*)data)->size_map += 2;
	}
	else if (key == 45)
	{
		//zoom "-"
		((t_fdf*)data)->size_map -= 2;
	}
	else if (key == 112)
	{
		//p
		data->z += 2 * data->size_map;
		data->z1 += 2 * data->size_map;
	}
	else if (key == 109)
	{
		//m
		data->z -= 2 * data->size_map;
		data->z1 -= 2 * data->size_map;
	}
	else if (key == 65361)
	{
		//gauche
		data->coord->x -= 10 * data->size_map;
		data->coord->x1 -= 10 * data->size_map;
	}
	else if (key == 65364)
	{
		//bas
		data->coord->y += 10 * data->size_map;
		data->coord->y1 += 10 * data->size_map;
	}
	else if (key == 65363)
	{
		//droite
		data->coord->x += 10 * data->size_map;
		data->coord->x1 += 10 * data->size_map;
	}
	else if (key == 65362)
	{
		//haut
		data->coord->y -= 10 * data->size_map;
		data->coord->y1 -= 10 * data->size_map;
	}
	else if (key == 119)
	{
		//rotate y "w"
		data->angle_y += 0.1;
	}
	else if (key == 97)
	{
		//rotate x "a"
		data->angle_x += 0.1;
	}
	else if (key == 115)
	{
		//rotate y "s"
		data->angle_y -= 0.1;
	}
	else if (key == 100)
	{
		//rotate x "d"
		data->angle_x -= 0.1;
	}
	else if (key == 65451)
	{
		//zoom "+"
		data->zoom += 1 * data->size_map;
	}
	else if (key == 65453)
	{
		//zoom "-"
		data->zoom -= 1 * data->size_map;
	}
	else if (key == 114)
	{
		//reset "r"
		data->zoom = 20;
		data->size_map = 1;
		data->angle_x = 0.8;
		data->angle_y = 0.8;
	}
	else
		return (0);
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	draw(data, coord);
	return (0);
}

void	mlx_in_data(t_fdf *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "FdF");
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	data->zoom = 20;
	data->size_map = 1;
	data->angle_x = 0.45;
	data->angle_y = 0.45;
	data->coord->x = 0;
	data->coord->y = 0;
	data->coord->x1 = 0;
	data->coord->y1 = 0;
}

int	main(int ac, char **av)
{
	t_fdf	*data;
	t_coord	coord;

	write(1, "u", 1);
	if (ac != 2)
		return (ft_putstr_fd("Usage: ./fdf file\n", 2), 1);
	check_error(av[1]);
	data = ft_calloc(1, sizeof(t_fdf));
	if (!data)
		exit(2);
	data->coord = &coord;
	fdf_init(av[1], data);
	check_data(data);
	mlx_in_data(data);
	data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->size_line, &data->endian);
	draw(data, coord);
	mlx_key_hook(data->win, keys, data);
	mlx_loop(data->mlx);
	return (0);
}

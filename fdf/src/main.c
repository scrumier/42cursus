/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/08 12:36:29 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

static int keys(int key, void *data)
{
	printf("key: %d\n", key);
	if (key == 65307)
	{
		mlx_destroy_window(((t_fdf*)data)->mlx, ((t_fdf*)data)->win);
		free_all((t_fdf*)data);
		exit(0);
	}
	if (key == )
	{
		//zoom "p"
		((t_fdf*)data)->size_map *= 1.2;
	}
	if (key == )
	{
		//zoom "m"
		((t_fdf*)data)->size_map /= 1.2;
	}
	if (key == 65361)
	{
		//gauche
		data->pos_x -= 10 * data->size_map;
	}
	if (key == 65364)
	{
		//bas
		data->pos_y += 10 * data->size_map;
	}
	if (key == 65363)
	{
		//droite
		data->pos_x += 10 * data->size_map;
	}
	if (key == 65362)
	{
		//haut
		data->pos_y -= 10 * data->size_map;
	}
	if (key == 119)
	{
		//rotate y "w"
		data->angle_y += 0.1 * data->size_map;
	}
	if (key == 97)
	{
		//rotate x "a"
		data->angle_x += 0.1 * data->size_map;
	}
	if (key == 115)
	{
		//rotate y "s"
		data->angle_y -= 0.1 * data->size_map;
	}
	if (key == 100)
	{
		//rotate x "d"
		data->angle_x -= 0.1 * data->size_map;
	}
	if (key == 61)
	{
		//zoom "+"
		data->zoom += 1 * data->size_map;
	}
	if (key == 45)
	{
		//zoom "-"
		data->zoom -= 1 * data->size_map;
	}
	mlx_clear_window(data->mlx, data->win);
	draw(data);
	return (0);
}

void	mlx_in_data(t_fdf *data)
{
	data->pos_x = 0;
	data->pos_y = 0;
	data->angle_x = 0;
	data->angle_y = 0;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "FdF");
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	data->data_addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->size_line, &data->endian);
	data->zoom = 20;
	data->angle = 0.78;
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	if (ac != 2)
		return (ft_putstr_fd("Usage: ./fdf file\n", 2), 1);
	check_error(av[1]);
	data = (t_fdf*)malloc(sizeof(t_fdf));
	fdf_init(av[1], data);
	check_data(data);
	mlx_in_data(data);
	draw(data);
	mlx_key_hook(data->win, keys, NULL);
	mlx_loop(data->mlx);
	return (0);
}

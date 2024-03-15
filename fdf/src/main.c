/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/15 13:58:45 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	mlx_in_data(t_fdf *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, HEIGHT, WIDTH, "FdF");
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	data->zoom = 20;
	data->size_map = 1;
	data->angle_x = 0.45;
	data->angle_y = 0.45;
	data->coef_z = 1;
}

int	main(int ac, char **av)
{
	t_fdf	*data;
	t_coord	coord;

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
	mlx_destroy_display(data->mlx);
	return (EXIT_SUCCESS);
}

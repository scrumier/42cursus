/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:22:19 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/05 14:53:29 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static float	maxi(float nbr1, float nbr2)
{
	if (nbr1 < nbr2)
		return (nbr2);
	return (nbr1);
}

static float	absolute(float nbr)
{
	if (nbr >= 0)
		return (nbr);
	return (nbr * -1);
}

static void	zoom(t_coord coord, t_fdf *data)
{
	coord.x *= data->zoom;
	coord.y *= data->zoom;
	coord.x1 *= data->zoom;
	coord.y1 *= data->zoom;
}

static void	color(int z, int z1, t_fdf *data)
{
	if (z || z1)
	{
		if (z > z1)
			mlx_pixel_put(data->mlx, data->win, 0xff0000, 0xff0000, 0xff0000);
		else
			mlx_pixel_put(data->mlx, data->win, 0x00ff00, 0x00ff00, 0x00ff00);
	}
	else
		mlx_pixel_put(data->mlx, data->win, 0xffffff, 0xffffff, 0xffffff);
}

void	bresenham(t_coord coord, t_fdf *data)
{
	float	x_coef;
	float	y_coef;
	float	max;
	int z;
	int z1;
	
	z = data->z_matrix[(int)coord.y][(int)coord.x];
	z1 = data->z_matrix[(int)coord.y1][(int)coord.x1];
	zoom(coord, data);
	color(z, z1, data);
	isometric(&coord.x, &coord.y, z, data->angle);
	isometric(&coord.x1, &coord.y1, z1, data->angle);
	x_coef = coord.x1 - coord.x;
	y_coef = coord.y1 - coord.y;
	max = maxi(absolute(x_coef), absolute(y_coef));
	x_coef /= max;
	y_coef /= max;
	while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
	{
		mlx_pixel_put(data->mlx, data->win, coord.x + 100, coord.y + 100, 0xffffff);
		coord.x += x_coef;
		coord.y += y_coef;
	}
}

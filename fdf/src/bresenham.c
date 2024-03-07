/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:22:19 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/07 17:34:00 by scrumier         ###   ########.fr       */
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

static void zoom(t_coord *coord, t_fdf *data)
{
    // Translate to center
    coord->x -= data->width / 2;
    coord->y -= data->height / 2;
    coord->x1 -= data->width / 2;
    coord->y1 -= data->height / 2;

    // Apply zoom
    coord->x *= data->zoom;
    coord->y *= data->zoom;
    coord->x1 *= data->zoom;
    coord->y1 *= data->zoom;

    // Translate back to original position
    coord->x += data->width / 2;
    coord->y += data->height / 2;
    coord->x1 += data->width / 2;
    coord->y1 += data->height / 2;
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
	zoom(&coord, data);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:22:19 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/12 15:42:21 by scrumier         ###   ########.fr       */
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
	// Apply zoom
	coord->x *= data->zoom;
	coord->y *= data->zoom;
	coord->x1 *= data->zoom;
	coord->y1 *= data->zoom;
}

void put_pixel_to_image(int x, int y, int color, t_fdf *data)
{
    int index = (y * data->size_line / 4) + x; 

    int color_value = mlx_get_color_value(data->mlx, color);

    *(unsigned int *)(data->data_addr + (index * (data->bits_per_pixel / 8))) = color_value;
}

void bresenham(t_coord coord, t_fdf *data)
{
	float x_coef;
	float y_coef;
	float max;

	data->z = data->z_matrix[(int)coord.y][(int)coord.x];
	data->z1 = data->z_matrix[(int)coord.y1][(int)coord.x1];
	zoom(&coord, data);
	isometric(&coord.x, &coord.y, data->z, data);
	isometric(&coord.x1, &coord.y1, data->z1, data);
	x_coef = coord.x1 - coord.x;
	y_coef = coord.y1 - coord.y;
	max = maxi(absolute(x_coef), absolute(y_coef));
	x_coef /= max;
	y_coef /= max;
	while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
	{
		can_i_put_pixel(data, coord.x, coord.y, 0x00ff00);
		coord.x += x_coef;
		coord.y += y_coef;
	}
}

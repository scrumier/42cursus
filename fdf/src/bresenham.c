/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:22:19 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/15 16:03:32 by scrumier         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{

	char	*dst;

	dst = data->data_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

t_color interpolate_color(t_color start, t_color end, float ratio)
{
    t_color result;

    result.red = start.red + (int)((end.red - start.red) * ratio);
    result.green = start.green + (int)((end.green - start.green) * ratio);
    result.blue = start.blue + (int)((end.blue - start.blue) * ratio);
    result.alpha = start.alpha + (int)((end.alpha - start.alpha) * ratio);
    return (result);
}

t_color calculate_color(t_fdf *data)
{
    float ratio;
    t_color start_color;
    t_color end_color;

	start_color = (t_color){0, 0, 255, 0};
	end_color = start_color;
	ratio = (data->z + data->z1) / 2.0f / data->max_z;
    return (interpolate_color(start_color, end_color, ratio));
}


void bresenham(t_coord coord, t_fdf *data)
{
	float	x_coef;
	float	y_coef;
	float	max;
	int		int_color;
	t_color color;

	data->z = data->z_matrix[(int)coord.y][(int)coord.x] * data->coef_z;
	data->z1 = data->z_matrix[(int)coord.y1][(int)coord.x1] * data->coef_z;
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
		color = calculate_color(data);
		int_color = ((color.red & 0xFF) << 16) | ((color.green & 0xFF) << 8) | (color.blue & 0xFF);
		if (can_i_put_pixel(coord.x + data->x, coord.y + data->y))
			my_mlx_pixel_put(data, coord.x + data->x, coord.y + data->y, int_color);
		coord.x += x_coef;
		coord.y += y_coef;
	}
}

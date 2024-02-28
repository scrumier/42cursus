/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:22:19 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/28 17:07:39 by scrumier         ###   ########.fr       */
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
	if (nbr > 0)
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

void	bresenham(t_coord coord, t_fdf *data)
{
	float	x_coef;
	float	y_coef;
	int		max;

	zoom(coord, data);
	x_coef = coord.x1 - coord.x;
	y_coef = coord.y1 = coord.y;
	max = maxi(absolute(x_coef), absolute(y_coef));
	x_coef /= max;
	y_coef /= max;
	while ((int)(coord.x - coord.x1) || (int)(coord.y - coord.y1))
	{
		mlx_pixel_put(data->mlx, data->win, coord.x, coord.y, 0xffffff);
		coord.x += x_coef;
		coord.y += y_coef;
	}
}

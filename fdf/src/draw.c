/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:01:57 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/04 13:42:36 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	do_bresenham(int y, int x, t_fdf *data, t_coord coords)
{
    coords.x = x;
    coords.y = y;
    if (x < data->width - 1)
    {
        coords.x1 = x + 1;
        coords.y1 = y;
        bresenham(coords, data);
    }
    if (y < data->height - 1)
    {
        coords.x1 = x;
        coords.y1 = y + 1;
        bresenham(coords, data);
    }
}

void    draw(t_fdf *data)
{
    int x;
    int y;
    t_coord coords;

    y = 0;
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            do_bresenham(y, x, data, coords);
        }
    }
}
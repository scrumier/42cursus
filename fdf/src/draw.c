/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:01:57 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/28 17:14:45 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void do_bresenham(int y, int x, t_fdf *data, t_coord coords)
{
    
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
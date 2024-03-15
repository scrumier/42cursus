/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 13:58:49 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/15 15:20:08 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void quit_fdf(t_fdf *data)
{
    mlx_destroy_image(data->mlx, data->img);
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free_all(data);
    exit(0);
}

void resize_coef(t_fdf *data, int key)
{
    if (key == PLUS)
        data->size_map *= 1.1;
    if (key == MINUS && data->size_map > 1)
        data->size_map /= 1.1;
    printf("data->size_map = %f\n", data->size_map);
}

void move(t_fdf *data, int key)
{
    if (key == LEFT)
    {
        data->x -= 10 * data->size_map;
        data->x1 -= 10 * data->size_map;
    }
    else if (key == RIGHT)
    {
        data->x += 10 * data->size_map;
        data->x1 += 10 * data->size_map;
    }
    else if (key == UP)
    {
        data->y -= 10 * data->size_map;
        data->y1 -= 10 * data->size_map;
    }
    else if (key == DOWN)
    {
        data->y += 10 * data->size_map;
        data->y1 += 10 * data->size_map;
    }
}

void change_angle(t_fdf *data, int key)
{
    if (key == W)
        data->angle_y -= 0.1;
    else if (key == A)
        data->angle_x -= 0.1;
    else if (key == S)
        data->angle_y += 0.1;
    else if (key == D)
        data->angle_x += 0.1;
}

void zoom_in_out(t_fdf *data, int key)
{
    if (key == PLUS_NUM)
        data->zoom += 1 * data->size_map;
    if (key == MINUS_NUM)
        data->zoom -= 1 * data->size_map;
}

void change_z(t_fdf *data, int key)
{
    if (key == P)
        data->coef_z += 1;
    else if (key == M)
        data->coef_z -= 1;
}

void reset(t_fdf *data)
{
    data->zoom = 20;
    data->size_map = 1;
    data->angle_x = 0.45;
    data->angle_y = 0.45;
    data->coef_z = 1;
    data->x = 0;
    data->y = 0;
}

void exec_keys(int key, t_fdf *data)
{
	printf("key = %d\n", key);
	if (key == ESC)
        quit_fdf(data);
	else if (key == PLUS || key == MINUS)
        resize_coef(data, key);
	else if (key == LEFT || key == RIGHT || key == UP || key == DOWN)
        move(data, key);
	else if (key == W || key == A || key == S || key == D)
        change_angle(data, key);
	else if (key == PLUS_NUM || key == MINUS_NUM)
        zoom_in_out(data, key);
	else if (key == P || key == M)
        change_z(data, key);
	else if (key == R)
        reset(data);
	else
		return ;
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, HEIGHT, WIDTH);
	draw(data, *(data->coord));
}

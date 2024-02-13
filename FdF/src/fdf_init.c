/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:17 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/12 21:51:50 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_init(t_fdf *fdf)
{
	(*fdf).mlx = mlx_init();
	(*fdf).win = mlx_new_window((*fdf).mlx, WIDTH, HEIGHT, "FDF");
	(*fdf).img = mlx_new_img((*fdf).mlx, WIDTH, HEIGHT);
	(*fdf).map = NULL;
	(*fdf).width = 0;
	(*fdf).height = 0;
	(*fdf).color = 0;
	(*fdf).depth = 0;
	(*fdf).offset_x = 0;
	(*fdf).offset_y = 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:03:38 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/08 12:04:16 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void isometric(float *x, float *y, int z, t_fdf *data)
{
    float temp_x = *x;
    float temp_y = *y;
    *x = (temp_x - temp_y) * cos(data->angle_x);
    *y = (temp_x + temp_y) * sin(data->angle_y) - z;
}

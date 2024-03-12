/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:03:38 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/12 12:51:49 by scrumier         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:03:38 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/07 17:30:40 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void isometric(float *x, float *y, int z, float angle)
{
    float temp_x = *x;
    *x = (temp_x - *y) * cos(angle);
    *y = (temp_x + *y) * sin(angle) - z;
}

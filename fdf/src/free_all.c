/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:20:56 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/14 18:12:02 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_all(t_fdf *data)
{
	int i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data->mlx);
	free(data);
}

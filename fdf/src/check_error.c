/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:13:15 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/12 18:11:49 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	check_error(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error: file not found\n", 2);
		exit(1);
	}
	close(fd);
}

void	check_data(t_fdf *data)
{
	int	i;
	int j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			j++;
		}
		if (data->width != j)
		{
			ft_putstr_fd("Error:1\n", 2);
			exit(2);
		}
		i++;
	}
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->z_matrix[i][j] < -100 || data->z_matrix[i][j] > 500)
			{
				ft_putstr_fd("Error:2\n", 2);
				exit(2);
			}
			j++;
		}
		i++;
	}
	if (data->height < 2 || data->width < 2)
	{
		ft_putstr_fd("Error:3\n", 2);
		exit(2);
	}
}

bool can_i_put_pixel(t_fdf *data, int x, int y)
{
    if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH)
        return (true);
    else
        return (false);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:13:15 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/08 12:28:17 by sonamcrumie      ###   ########.fr       */
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

	i = 0;
	while (i < data->height)
	{
		if (data->width != ft_countwords(data->z_matrix[i]))
		{
			ft_putstr_fd("Error: map is not a rectangle\n", 2);
			exit(1);
		}
		i++;
	}
	//check if the map is only numbers and spaces
	i = 0;
	while (i < data->height)
	{
		if (!ft_isnumber(data->z_matrix[i]))
		{
			ft_putstr_fd("Error: map is not a rectangle\n", 2);
			exit(1);
		}
		i++;
	}
	if (data->height < 2 || data->width < 2)
	{
		ft_putstr_fd("Error: map is too small\n", 2);
		exit(1);
	}
}

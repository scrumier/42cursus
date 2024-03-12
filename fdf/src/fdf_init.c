/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:17 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/12 16:24:49 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_height(char *file)
{
	int		fd;
	int		height;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	height = 0;
	while (get_next_line(fd))
	{
		height++;
	}
	close(fd);
	return (height);
}

static int	get_width(char *file)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	line = get_next_line(fd);
	width = ft_countwords(line);
	free(line);
	close(fd);
	return (width);
}

static void	fill(int *z_line, char *line)
{
	int		i;
	char	**nbr;

	nbr = ft_split(line, ' ');
	i = 0;
	while (nbr[i + 1])
	{
		z_line[i] = ft_atoi(nbr[i]);
		i++;
	}
	free(nbr);
}

void    fdf_init(char *file, t_fdf *data)
{
	int     fd;
	int     i;
	char    *line;

	data->height = get_height(file); //hauteur
	data->width = get_width(file); //largeur
	data->z_matrix = ft_calloc( data->height + 1, sizeof(int *));
	if (!data->z_matrix)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = ft_calloc( data->width + 1, sizeof(int));
		if (data->z_matrix[i] == NULL)
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill(data->z_matrix[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	data->size_map = (data->width + data->height) / 2;
}
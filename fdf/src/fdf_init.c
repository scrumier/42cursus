/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:57:17 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/23 18:28:38 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// peut etre un probleme ici
static int	get_height(char *file)
{
	int		fd;
	int		height;

	fd = open(file, O_RDONLY);
	height = 0;
	while (get_next_line(fd) != NULL)
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
	while (nbr[i] != NULL)
	{
		z_line[i] = ft_atoi(nbr[i]);
		i++;
	}
	free(nbr);
}

void	fdf_init(char file, t_fdf *data)
{
	int		fd;
	int		i;
	char	*line;

	data->height = get_height(&file);
	data->width = get_width(&file);
	data->z_matrix = (int **)malloc(sizeof(int *) * data->height);
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * data->width);
	fd = open(&file, O_RDONLY);
	i = 0;
	line = NULL;
	while (line != NULL)
	{
		line = get_next_line(fd);
		fill(data->z_matrix[i], line);
		free(line);
	}
	close(fd);
	data->z_matrix[i] = NULL;
}
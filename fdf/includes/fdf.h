/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:39:43 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/08 12:26:17 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "keys.h"

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	float	angle_y;
	float	angle_x;
	int 	size_map;

	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_fdf;

typedef struct s_coord
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_coord;


int		ft_countwords(char *s);
void	fdf_init(char *file, t_fdf *data);
void    bresenham(t_coord coord, t_fdf *data);
void    draw(t_fdf *data);
void isometric(float *x, float *y, int z, float angle);


#endif

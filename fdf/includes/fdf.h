/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:39:43 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/12 18:17:08 by scrumier         ###   ########.fr       */
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
# include <stdbool.h>
# include "keys.h"

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_coord
{
	float	x;
	float	y;
	float	x1;
	float	y1;
}			t_coord;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	float	angle_y;
	float	angle_x;
	int		z;
	int		z1;
	int		coef_z;
	float	x;
	float	y;
	float	x1;
	float	y1;
	int 	size_map;

	void	*mlx;
	void	*win;
	void	*img;
	char	*data_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	t_coord	*coord;
}			t_fdf;




int		ft_countwords(char *s);
void	fdf_init(char *file, t_fdf *data);
void    bresenham(t_coord coord, t_fdf *data);
void    draw(t_fdf *data, t_coord coords);
void 	isometric(float *x, float *y, int z, t_fdf *data);
void	free_all(t_fdf *data);
void	check_error(char *file);
void	check_data(t_fdf *data);
int		ft_isnumber(int c);
bool	can_i_put_pixel(t_fdf *data, int x, int y);

#endif

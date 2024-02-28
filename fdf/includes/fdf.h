/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:39:43 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/28 17:04:18 by scrumier         ###   ########.fr       */
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
# include "keys.h"

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;

	void	*mlx;
	void	*win;
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


#endif

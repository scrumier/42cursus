/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonam <sonam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:39:43 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/14 13:42:47 by sonam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include "keys.h"

# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	int		**map;
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		depth;
	int		offset_x;
	int		offset_y;
}	t_fdf;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	fdf_init(t_fdf *fdf);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:39:43 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/23 13:47:23 by scrumier         ###   ########.fr       */
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
	int		width;
	int		height;
	int		**z_matrix;

	void	*mlx;
	void	*win;
}			t_fdf;

int		ft_countwords(char *s);
void	fdf_init(char file, t_fdf *data);


#endif

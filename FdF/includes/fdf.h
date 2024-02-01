/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:39:43 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/01 01:12:29 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../get_next_line/get_next_line.h"
# include "../libft/libft_src/libft.h"
# include "../mlx_linux/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>


# define WIDTH 1920
# define HEIGHT 1080

typedef struct  s_map
{
    void    *mlx;
    void    *win;
}        t_map;

typedef struct  s_fdf
{
    void    *mlx;
    void    *win;
}        t_fdf;


#endif
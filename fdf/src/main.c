/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/13 15:37:07 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void open_fd(int *fd, char str)
{
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		//gerer l'erreur
	}
}

int	main(int ac, char **av)
{
	int		fd;
	t_fdf	fdf;

	check_error(ac, av);
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./fdf <filename>\n", 2);
		return (1);
	}
	fdf_init(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}

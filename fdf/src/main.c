/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonam <sonam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:27:27 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/14 14:19:46 by sonam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main()
{
	t_fdf	fdf;

	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./fdf <filename>\n", 2);
		return (1);
	}
	fdf_init(&fdf);
	mlx_loop(fdf.mlx);
	return (0);
}

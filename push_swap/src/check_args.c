/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:57:02 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/13 13:03:22 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_twice(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	check_nbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '-')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_check_args_bis(char **args, int i)
{
	long	tmp;

	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!check_nbr(args[i]))
			ft_error("Error", NULL, NULL);
		if (is_twice(tmp, args, i))
			ft_error("Error", NULL, NULL);
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error", NULL, NULL);
		i++;
	}
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	char	**args;	

	i = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error("Error", NULL, NULL);
	}
	else
	{
		i = 1;
		args = argv;
	}
	ft_check_args_bis(args, i);
	if (argc == 2)
		ft_free(args);
}

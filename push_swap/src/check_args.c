/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:57:02 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/15 13:04:37 by scrumier         ###   ########.fr       */
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

static void	check_multiple_args(char **args, int i)
{
	long long	tmp;

	while (args[i])
	{
		if (!check_nbr(args[i]))
			ft_error_args("Error\n", NULL);
		tmp = ft_atoi(args[i]);
		if (is_twice(tmp, args, i))
			ft_error_args("Error\n", NULL);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ft_error_args("Error\n", NULL);
		i++;
	}
}

static void	check_single_arg(char **args, int i)
{
	long long	tmp;

	while (args[i])
	{
		if (!check_nbr(args[i]))
			ft_error_args("Error\n", args);
		tmp = ft_atoi(args[i]);
		if (is_twice(tmp, args, i))
			ft_error_args("Error\n", args);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ft_error_args("Error\n", args);
		i++;
	}
}



void	ft_check_args(int argc, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	if (argc == 2 && count_nbr(argv[1]) > 1)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			ft_error("Error", NULL, NULL);
		check_single_arg(args, i);
	}
	else
	{
		i = 1;
		args = argv;
		check_multiple_args(args, i);
	}
	if (argc == 2)
		ft_free(args);
}

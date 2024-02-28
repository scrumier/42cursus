/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:57:02 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/02/26 14:07:16 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	long long	tmp;

	while (args[i])
	{
		if (!check_nbr(args[i]))
			ft_error("Error", NULL, NULL);
		tmp = ft_atoi(args[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ft_error("Error", NULL, NULL);
		i++;
	}
}

static int	count_nbr(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (ft_isdigit(arg[i]) || arg[i] == '-' || arg[i] == '+')
		{
			count++;
			i++;
			while (ft_isdigit(arg[i]))
				i++;
		}
		else
			i++;
	}
	if (count < 2)
		ft_error("", NULL, NULL);
	return (count);
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

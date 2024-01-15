/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:53:52 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/11 15:08:02 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi_bis(const char *str)
{
	int				sign;
	long long int	i;

	i = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		ft_error();
	return (sign * i);
}

t_list	*ft_process_bis(char **argv)
{
	t_list	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		j = ft_atoi_bis(tmp[i]);
		ft_lstadd_back(&a, ft_lstnew(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_list	*process(int argc, char **argv)
{
	t_list	*list_a;
	int		i;
	int		j;

	i = 1;
	list_a = NULL;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		list_a = ft_process_bis(argv);
	else
	{
		while (i < argc)
		{
			j = ft_atoi_bis(argv[i]);
			ft_lstadd_back(&list_a, ft_lstnew(j));
			i++;
		}
	}
	return (list_a);
}

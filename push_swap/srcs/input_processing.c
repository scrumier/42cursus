/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:53:52 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/17 10:50:44 by sonamcrumie      ###   ########.fr       */
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

void process(int argc, char **argv, t_list **list_a)
{
    t_list *head_a;
	t_list *new;
    int i, j;

	(void)head_a;
    i = 1;
    if (argc < 2)
        ft_error();

    if (argc == 2)
    {
        *list_a = ft_process_bis(argv);
    }
    else
    {
        *list_a = NULL;

        while (i < argc)
        {
            j = ft_atoi_bis(argv[i]);
            new = ft_lstnew(j);
            ft_lstadd_back(list_a, new);
            i++;
        }
    }
}


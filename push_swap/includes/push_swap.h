/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:42:42 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/14 12:09:01 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list_move
{
	int					ra;
	int					rb;
	int					rra;
	int					rrb;
}				t_list_move;

void	sort(t_list **list_a);
int	check_argv(char **args);
int	checkdup(t_list *list_a);
int	ft_checksorted(t_list *list_a);
int	ft_rev_checksorted(t_list *list_b);
t_list	*process(int argc, char **argv);
void	ft_error(void);
void	free_list(t_list **list);
int	check_error(char **argv, int i, int j);

int	sa(t_list **list_a, int j);
int	sb(t_list **list_b, int j);
int	ss(t_list **list_a, t_list **list_b);
int	pa(t_list **list_a, t_list **list_b);
int	pb(t_list **list_a, t_list **list_b);
int	ra(t_list **list_a, int i);
int	rb(t_list **list_b, int i);
int	rr(t_list **list_a, t_list **list_b);
int	rrb(t_list **list_a, int i);
int	rra(t_list **list_b, int i);
int rrr(t_list **list_a, t_list **list_b);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:42:42 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/16 13:53:08 by scrumier         ###   ########.fr       */
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
void	process(int argc, char **argv, t_list **list_a);
void	ft_error(void);
void	free_list(t_list **list);
int	check_error(char **argv, int i, int j);
void put_index(t_list *list_a, t_list *list_b);
void	ft_freestr(char **lst);

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:31:06 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/15 13:05:06 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

t_list	*ft_lstnew(int value);
int		ft_lstsize(t_list *head);
t_list	*ft_lstlast(t_list *head);
void	ft_lstadd_back(t_list **list, t_list *new);
void	ft_lstadd_front(t_list **list, t_list *new);

void	ft_free(char **str);
int		count_nbr(char *arg);
void	free_list(t_list *list);
int		is_sorted(t_list **list);
void 	ft_error_args(char *str, char **arg);
void	ft_check_args(int argc, char **argv);
int		get_distance(t_list **list, int index);
void	free_all(t_list **list_a, t_list **list_b);
void	ft_error(char *msg, t_list **a, t_list **b);
void	make_top(t_list **list_a, t_list **list_b, int distance);

void	index_list(t_list **list);
int		get_min(t_list **list, int val);
void	sort_3(t_list **list_a, t_list **list_b);
void	sort_4(t_list **list_a, t_list **list_b);
void	sort_5(t_list **list_a, t_list **list_b);
void	radix_sort(t_list **list_a, t_list **list_b);
void	simple_sort(t_list **list_a, t_list **list_b);
void	make_ra_sa_rra(t_list **list_a, t_list **list_b);
void	calculate_min_values(t_list **list_a, int *min, int *next_min);
void	sort_logic(t_list **list_a, t_list **list_b, int min, int next_min);

int		rotate(t_list **list);
int		reverse_rotate(t_list **list);
int		push(t_list **list_to, t_list **list_from);
int		swap(t_list **list, t_list **list_a, t_list **list_b);

int		sa(t_list **list_a, t_list **list_b);
int		sb(t_list **list_a, t_list **list_b);
int		ss(t_list **list_a, t_list **list_b);
int		pa(t_list **list_a, t_list **list_b);
int		pb(t_list **list_b, t_list **list_a);
int		ra(t_list **list_a, t_list **list_b);
int		rb(t_list **list_a, t_list **list_b);
int		rr(t_list **list_a, t_list **list_b);
int		rra(t_list **list_a, t_list **list_b);
int		rrb(t_list **list_a, t_list **list_b);
int		rrr(t_list **list_a, t_list **list_b);

#endif
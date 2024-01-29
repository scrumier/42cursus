/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:42:42 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/18 14:36:27 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_list_move
{
	int					ra;
	int					rb;
	int					rra;
	int					rrb;
}				t_list_move;

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}				t_list;

//print
void print_best_way(t_list_move *move);
void print_list(t_list *list_a, t_list *list_b);

//algo
void	sort(t_list **list_a, t_list **list_b);
void	sort_best_way(t_list_move *move, t_list **list_a, t_list **list_b);

//parse
void 	put_index(t_list *list_a, t_list *list_b);
void	process(int argc, char **argv, t_list **list_a);
void	find_best_way(t_list_move **move, t_list *list_a, t_list *list_b);

//error
void	ft_error(void);
int		check_argv(char **args);
int		checkdup(t_list *list_a);
int		ft_checksorted(t_list *list_a);
int		ft_rev_checksorted(t_list *list_b);
int		check_error(char **argv, int i, int j);

//utils
int		ft_isalpha(int c);
int		ft_isdigit(int c);
t_list *ft_lstnew(int value);
void	ft_freestr(char **lst);
size_t	ft_strlen(const char *s);
void	free_list(t_list **list);
int	 	ft_lstsize(t_list *list);
t_list	*ft_lstlast(t_list *lst);
void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	free_list_move(t_list_move *list);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//move
int		sa(t_list **list_a, int j);
int		sb(t_list **list_b, int j);
int		ra(t_list **list_a, int i);
int		rb(t_list **list_b, int i);
void	rra(t_list **list_b, int j);
void	rrb(t_list **list_a, int j);
int		pa(t_list **list_a, t_list **list_b, int j);
int		pb(t_list **list_a, t_list **list_b, int j);
int		rr(t_list **list_a, t_list **list_b);
int		ss(t_list **list_a, t_list **list_b);
void 	rrr(t_list **list_a, t_list **list_b, int j);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:56:10 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/01/18 12:30:36 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	fill;
	size_t			i;

	str = s;
	fill = c;
	i = 0;
	while (n > 0)
	{
		str[i] = fill;
		i++;
		n--;
	}
	return (s);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset((void *)s, 0, n);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;

	srclen = ft_strlen((char *)src);
	if (srclen + 1 < size)
	{
		ft_memcpy(dst, src, srclen + 1);
	}
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (srclen);
}

void	ft_error(void)
{	
	write (2, "Error\n", 6);
	exit(1);
}

int	sign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	digit(int c)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	return (0);
}

int	space(int c)
{
	if (c == ' ')
		return (1);
	return (0);
}

int	check_error(char **argv, int i, int j)
{
	while (argv[i])
	{
		j = 0;
		while ((argv[i][j] != '\0'))
		{
			if (sign(argv[i][j]))
			{
				j++;
				if (!digit(argv[i][j]))
					return (0);
			}
			else if (digit(argv[i][j]))
			{
				j++;
				if (argv[i][j] == '\0')
					break ;
				if (!digit(argv[i][j]) && !space(argv[i][j]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	free_list_move(t_list_move *list)
{
	t_list_move	*tmp;

	tmp = NULL;
	if (!list)
		return ;
	list->ra = 0;
	list->rb = 0;
	list->rra = 0;
	list->rrb = 0;
	free(list);
	list = tmp;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dst;
	const char	*source;

	if (!dest && !src)
		return (0);
	dst = (char *)dest;
	source = (const char *)src;
	if (!dst) {
		write(1, "ERROR\n", 6);
		return NULL; // return immediately if dst or source is NULL
	}
	while (n > 0 && *source)
	{
		*dst++ = *source++;
		n--;
	}
	return (dest);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	if (!list)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		(*list)->value = 0;
		free(*list);
		*list = tmp;
	}
}

void	ft_freestr(char **lst)
{
	char	*str;

	if (!lst)
		return ;
	while (*lst)
	{
		str = *lst;
		lst++;
		free(str);
	}
	*lst = NULL;
}

int ft_lstsize(t_list *list)
{
    int size;

	size = 0;
    while (list != NULL)
    {
        size++;
        list = list->next;
    }
    return size;
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	if (!(*lst)->next)
	{
		(*lst)->next = new;
		return ;
	}
	last = *lst;
	while (last->next)
	{
		last = last->next;
	}
	last->next = new;
}

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

static void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, &(*s), ft_strlen(s));
}

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

t_list *ft_lstnew(int value)
{
    t_list *new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
    if (new_node == NULL)
        ft_error();
    new_node->value = value;
    new_node->next = NULL;
    return (new_node);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*target;
	size_t	max;

	max = (size_t) - 1;
	if (size == 0 || nmemb == 0)
	{
		target = malloc(0);
		if (target == NULL)
			return (NULL);
		return (target);
	}
	else if (nmemb >= max / size)
		return (NULL);
	else
		target = malloc(nmemb * size);
	if (target == NULL)
		return (NULL);
	ft_bzero(target, nmemb * size);
	return (target);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
	{
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (len > str_len - start)
		len = str_len - start;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}

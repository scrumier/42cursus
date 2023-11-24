/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:32:54 by scrumier          #+#    #+#             */
/*   Updated: 2023/11/21 13:52:21 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*new_elem;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	newlist = NULL;
	new_elem = NULL;
	tmp = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		new_elem = ft_lstnew(tmp);
		if (!new_elem)
		{
			free(tmp);
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, new_elem);
		lst = lst->next;
	}
	return (newlist);
}

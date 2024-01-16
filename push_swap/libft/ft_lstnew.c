/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:32:58 by scrumier          #+#    #+#             */
/*   Updated: 2024/01/15 16:06:09 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*nlst;

	nlst = (t_list *)malloc(sizeof(t_list));
	if (!nlst)
		return (0);
	nlst->value = content;
	nlst->next = NULL;
	return (nlst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:19:43 by scrumier          #+#    #+#             */
/*   Updated: 2024/03/19 14:21:26 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		handle_no_event(t_fdf *data)
{
	(void)data;
	return (0);
}

int		handle_keypress(int key, t_fdf *data)
{
	exec_keys(key, data);
	return (0);
}

int		handle_keyrelease(int key, t_fdf *data)
{
	(void)data;
	(void)key;
	return (0);
}

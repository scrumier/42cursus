/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:25:59 by scrumier          #+#    #+#             */
/*   Updated: 2024/02/23 15:39:00 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_countwords(char *s)
{
    int i;
    int count;

    i = 0;
    count = 0;
    if (!s)
        return (0);
    while (s[i])
    {
        if (s[i] != ' ')
        {
            count++;
            while (s[i] && s[i] != ' ')
                i++;
        }
        else
            i++;
    }
    return (count);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonamcrumiere <sonamcrumiere@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:36:53 by sonamcrumie       #+#    #+#             */
/*   Updated: 2023/12/12 16:20:57 by sonamcrumie      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (NULL);
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	s1_len = 0;
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = 0;
	if (s2)
		s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (!str)
		return (NULL);
	if (s1)
		ft_strlcpy(str, s1, s1_len + 1);
	else
		str[0] = '\0';
	if (s2)
		ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		if (size > 0)
			dst[i] = '\0';
	}
	return (src_len);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (unsigned char)c))
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

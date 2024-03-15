/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrumier <scrumier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:36:49 by sonamcrumie       #+#    #+#             */
/*   Updated: 2024/03/15 12:54:23 by scrumier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char    buff[BUFFER_SIZE + 1] = "\0";
    int            check_read;
    char        *line;
    static int    check_buff = 0;

    line = check_input_and_init_line_gnl(fd);
    if (!line)
        return (free(line), NULL);
    if (buff[0] != 0)
    {
        ft_memcpy_gnl(buff + 0, buff + ft_check_buff_gnl(buff, 2));
        line = ft_strjoin_gnl(line, buff);
        if (!line)
            return (free(line), NULL);
        check_buff = ft_check_buff_gnl(buff, 1);
        if (buff[check_buff] == '\n')
            return (line);
    }
    check_read = read(fd, buff, BUFFER_SIZE);
    buff[check_read] = 0;
    if (check_read < 0)
        return (ft_bzero_and_free_gnl(buff, line));
    if (check_read <= 0 && check_buff == 0)
        return (free(line), NULL);
    return (print_line_gnl(line, buff, &check_buff, fd));
}

char    *ft_strdup_gnl(char *s)
{
    size_t    j;
    char    *res;

    j = 0;
    if (!s)
        return (NULL);
    res = malloc (sizeof(char) * (ft_strlen_gnl(s) + 1));
    if (!res)
        return (NULL);
    while (j < ft_strlen_gnl(s) && s[j])
    {
        res[j] = s[j];
        j++;
    }
    res[j] = '\0';
    return ((char *)res);
}

char    *ft_strjoin_gnl(char *s1, char *s2)
{
    size_t        i;
    size_t        j;
    char        *s3;

    j = 0;
    i = 0;
    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup_gnl(s2));
    s3 = malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
    if (!s3)
        return (free(s1), NULL);
    while (s1[i])
    {
        s3[i] = s1[i];
        i++;
    }
    while (s2[j] && s2[j - 1] != '\n')
        s3[i++] = s2[j++];
    s3[i] = '\0';
    return (free(s1), s3);
}

int    ft_check_buff_gnl(char *buff, int choice)
{
    ssize_t    i;

    i = 0;
    if (choice == 1)
    {
        while (i < BUFFER_SIZE)
        {
            if (buff[i] == '\n' || buff[i] == '\0')
                return (i);
            i++;
        }
    }
    if (choice == 2)
    {
        while (i < BUFFER_SIZE)
        {
            if (buff[i] == '\n')
                return (i + 1);
            i++;
        }
    }
    return (i);
}

char    *check_input_and_init_line_gnl(int fd)
{
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = malloc(1 * sizeof(char));
    if (line)
        line[0] = '\0';
    return (line);
}

char    *ft_bzero_and_free_gnl(char *buff, char *line)
{
    ft_bzero_gnl(buff, 1);
    return (free(line), NULL);
}

void    ft_bzero_gnl(void *s, size_t n)
{
    char    *temp;
    size_t    i;

    temp = (char *)s;
    i = 0;
    while (i < n)
    {
        temp[i] = '\0';
        i++;
    }
}

size_t    ft_strlen_gnl(char *s)
{
    size_t    i;

    i = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            return (i + 1);
        i++;
    }
    return (i);
}

char    *ft_memcpy_gnl(char *dst, char *src)
{
    int    i;

    if (dst == NULL && src == NULL)
        return (NULL);
    i = 0;
    while (src[i] != 0)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
    return (dst);
}

char    *print_line_gnl(char *line, char *buff, int *check_buff, int fd)
{
    *check_buff = ft_check_buff_gnl(buff, 1);
    if (*check_buff < BUFFER_SIZE)
    {
        line = ft_strjoin_gnl(line, buff);
        if (!line)
            return (free(line), NULL);
    }
    else
    {
        while (*check_buff == BUFFER_SIZE)
        {
            line = ft_strjoin_gnl(line, buff);
            if (!line)
                return (free(line), NULL);
            buff[read(fd, buff, BUFFER_SIZE)] = 0;
            *check_buff = ft_check_buff_gnl(buff, 1);
        }
        line = ft_strjoin_gnl(line, buff);
        if (!line)
            return (free(line), NULL);
    }
    return (line);
}

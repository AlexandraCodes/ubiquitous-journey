/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:41:53 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/13 02:12:20 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int     ft_atoi(char *nptr)
{
    int     i;
    int     res;

    i = 0;
    res = 0;
    while (nptr[i])
    {
        res = res * 10;
        res = res + (nptr[i] - 48);
        i++;
    }
    return res;
}

char    *ft_strnew(int size)
{
    char    *str;
    int     i;

    i = 0;
    str = (char *)malloc(sizeof(char) * (size + 1));
    if (!str || size == 0)
        return (NULL);
    while (i < size + 1)
    {
        str[i] = '\0';
        i++;
    }
    if (!str)
        return (NULL);
    return (str);
}

char    *ft_strchr(char *str, int c)
{
    unsigned int    i;
    unsigned int    len;

    i = 0;
    len = 0;
    while (str[len] != '\0')
        len++;
    while (i <= len)
    {
        if (str[i] == (char)c)
            return ((char *)str + i);
        i++;
    }
    return (NULL);
}

int     ft_strlen(char *s)
{
    int     i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

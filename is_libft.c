/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:41:53 by alecasti          #+#    #+#             */
/*   Updated: 2021/05/20 15:51:41 by alecasti         ###   ########.fr       */
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

int     ft_strchr(char *str, char c)
{
    unsigned int    i;
    unsigned int    len;

    i = 0;
    len = ft_strlen(str);
    while (i <= len)
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int     ft_strlen(char *s)
{
    int     i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


void    int_to_str(t_pf *obj, int num, char *str)
{
    int     i;
    int     j;

    i = 0;
    j = 12;
    if (num < 0)
    {
        i++;
        num = -num;
    }
    while (num > 0)
    {
        str[j] = ((num % 10) + '0');
        j--;
        num = num/10;
    }
    // set the minus flag, then write num normal
    if (i == 1)
        str[0] = '-';
    while (++j < 13)
        str[i++] = str[j];
    str[i] = 0;
    obj->conv_len = i;
}

void	convert_to_base_str(t_pf *obj, int num, char *str)
{
	int		i;
	int		j;
	
	i = 12;
	j = 0;
	while (num > 0)
	{
		if ((num % obj->base) > 9)
		{
			if (obj->flags & F_CAPITAL)
				str[i] = ('A' + ((num % obj->base) - 10));
			else
				str[i] = ('a' + ((num % obj->base) - 10));
		}
		else
			str[i] = ('0' + (num % obj->base));
		i--;
		num = num / obj->base;
	}
	while (++i < 13)
		str[j++] = str[i];
	str[j] = 0;
    obj->conv_len = j;
}


//////

void    *ft_memset(void *b, int c, unsigned int size)
{
    unsigned char   *dst;
    unsigned int    i;

    i = 0;
    dst = (unsigned char *)b;
    while (i < size)
    {
        dst[i] = (unsigned char)c;
        i++;
    }
    return (dst);
}
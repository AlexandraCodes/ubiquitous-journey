/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:35:16 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/15 16:33:26 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

void    execute_identifier(t_details deets, char letter, va_list arg, int *width)
{
    //char    type_char;
    char    *type_str;
    //int     type_int;
/*
    if (letter == 'c')
    {
        type_char = va_arg(arg, int);
        ft_putchar(type_char);
    }
*/
    if (letter == 's')
    {
        type_str = va_arg(arg, char *);
        print_str(deets, type_str, width);
    }
    //if (letter == 'p')
    //    print_ptr();
//    if (letter == 'd' /*|| letter == 'i'*/)
/*    {
        type_int = va_arg(arg, int);
        print_dec(deets, type_int);
    }
*/
    /*
    if (letter == 'u')
        print_int();
    if (letter == 'x' || letter == 'X')
        print_hex();
    */
}

void    print_str(t_details details, char *str, int *width)
{
    int     len;
    int     i;
    int     min_space;
    int     min_word;

    len = ft_strlen(str);
    min_word = minimum_word_length(width[1], len);
    min_space = minimum_space_size(width[0], min_word);
    /*
    if ((width[1] < len) && (width[1] >= 0))
        min_word = width[1];
    if (((width[1] >= len) && (width[1] >= 0)) || (width[1] < 0))
        min_word = len;
    if (((width[0] < min_word) && (width[0] >= 0)) || (width[0] < 0))
        min_space = min_word;
    if ((width[0] >= min_word) && (width[0] >= 0))
        min_space = width[0];
    */
    if (details.minus)
    {
        write (1, ft_strcut(str, min_word), min_word);
        i = -1;
        while (++i < (min_space - min_word))
            write(1, " ", 1);
    }
    else
    {
        i = -1;
        while (++i < (min_space - min_word))
            write(1, " ", 1);
        write(1, ft_strcut(str, min_word), min_word);
    }
}

int     minimum_word_length(int min_len, int len)
{
    if ((min_len < len) && (min_len >= 0))
        return min_len;
    return len;
    /*;
    if (((min_len >= len) && (min_len >= 0)) || (min_len < 0))
        return len;
    */
}

int     minimum_space_size(int min_space, int min_len)
{
    if ((min_space >= min_len) && (min_space >= 0))
        return min_space;
    return min_len;
    /*
    if (((min_space < min_len) && (min_space >= 0)) || (min_space < 0))
        return min_len;
    */
}

char    *ft_strcut(char *str, int len)
{
    char    *copy;
    int     i;

    i = 0;
    copy = ft_strnew(len);
    copy[len] = '\0';
    while (i < len)
    {
        copy[i] = str[i];
        i++;
    }
    return (copy);
}

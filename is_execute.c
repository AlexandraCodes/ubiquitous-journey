/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:35:16 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/15 15:02:24 by alecasti         ###   ########.fr       */
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

   // min_space = width[0];
   // mim_word = width[1];
    len = ft_strlen(str);
    /*
    if (!details.min && !details.max)
        write(1, str, len);
*/
    //
    //
    if ((width[1] < len) && (width[1] >= 0))
        min_word = width[1];
    if (((width[1] >= len) && (width[1] >= 0)) || (width[1] < 0))
        min_word = len;
    if (((width[0] < min_word) && (width[0] >= 0)) || (width[0] < 0))
        min_space = min_word;
    if ((width[0] >= min_word) && (width[0] >= 0))
        min_space = width[0];
    if (details.minus)
    {
        write (1, ft_strcut(str, min_word), min_word);
        i = 0;
        while (i < (min_space - min_word))
        {
            write(1, " ", 1);
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < (min_space - min_word))
        {
            write(1, " ", 1);
            i++;
        }
        write(1, ft_strcut(str, min_word), min_word);
    }
    //
    //
    /*
    i = 0;
    if (details.minus)
    {
        while (i < 
    }
    //
    //

  //  printf("\nTHIS IS MIN -- %d\nTHIS IS MAX -- %d\n", width[0], width[1]);
    if (details.min && !details.max)
    {
        //printf("details.min && !details.max");
        if (width[0] < len) // details.minus doesn't matter
            write(1, str, len);
        else
        {
            i = 0;
            if (details.minus)
            {
                write(1, str, len);
                while (i < (width[0] -len))
                {
                    write(1, " ", 1);
                    i++;
                }
               // write(1, " ", (width[1] - len));
            }
            else
            {
                while (i < (width[0] - len))
                {
                    write(1, " ", 1);
                    i++;
                }
               // write(1, " ", (width[1] - len));
                write(1, str, len);
            }
        }
    }

    if (details.max && !details.min)
    {
        if (width[1] < len) // write substring -- minus doesn't matter, same either way
            write(1, ft_strcut(str, width[1]), width[1]);
        else // minus doesn't matter
            write(1, str, len);
    }

    if (details.max && details.min)
    {
        if (width[0] < width[1])
        {
            if (width[1] < len)
                write(1, ft_strcut(str, width[1]), width[1]);
            else
                write(1, str, len);
        }
        else
        {
            if (width[1] < len)
            {
                if (details.minus)
                {
                    write(1, ft_strcut(str, width[1]), width[1]);
                    write(1, " ", (width[0] - width[1]));
                }
                else
                {
                    i = 0;
                    while (i++ < (width[0] - width[1]))
                        write(1, " ", 1);
                    //write(1, " ", (width[1] - width[2]));
                    write(1, ft_strcut(str, width[1]), width[1]);
                }
            }
            else
            {
                if (details.minus)
                {
                    write(1, str, len);
                    write(1, " ", (width[0] - width[1]));
                }
                else
                {
                    write(1, " ", (width[0] - width[1]));
                    write(1, str, len);
                }
            }
        }
    }*/
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:31:12 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/15 17:11:07 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct      s_details
{
    unsigned int    flag:1;
    unsigned int    min:1;
    unsigned int    period:1;
    unsigned int    max:1;

    unsigned int    minus:1;
    unsigned int    zero:1;

}                   t_details;

int     is_minus(char letter);
int     is_zero(char letter);
int     is_star(char letter);
int     is_period(char letter);
int     is_flag(char letter);
int     is_integer(char letter);


void    execute_identifier(t_details details, char letter, va_list arg, int *width); 


void    print_str(t_details details, char *str, int *width);
int     minimum_word_length(int min, int len);
int     minimum_space_size(int min_space, int min_word);
int     print_whitespace(int len);
void    print_substr(char *str, int len);


char    *ft_strnew(int size);
int     ft_atoi(char *nptr);
void    ft_putchar(char c);
char    *ft_strchr(char *str, int c);
int     ft_strlen(char *str);

int     is_present(char modifier, char *type);
int     ft_printf(char *str, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:31:12 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/04 20:20:58 by alecasti         ###   ########.fr       */
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
    unsigned int    pound:1;
    unsigned int    plus:1;
    unsigned int    space:1;

}                   t_details;

int     is_minus(char letter);
int     is_zero(char letter);
int     is_pound(char letter);
int     is_plus(char letter);
int     is_space(char letter);
int     is_star(char letter);
int     is_period(char letter);
int     is_flag(char letter);

int     is_present(char modifier, char *type)
int     ft_printf(char *str, ...)

#endif

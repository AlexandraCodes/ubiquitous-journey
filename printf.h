/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 13:31:12 by alecasti          #+#    #+#             */
/*   Updated: 2021/05/20 16:31:17 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>

# define F_MINUS	(1 << 0)
# define F_ZERO		(1 << 1)
# define F_STAR		(1 << 2)

# define F_CAPITAL	(1 << 3)

# define F_CONVSET	(1 << 4)

# define F_PERIOD	(1 << 5)
# define F_FWIDTH	(1 << 6)



typedef struct 		s_pf
{
	char			*str;
	va_list			list;

	int				flags;
	char			item;
	int				base;

	int				conv_len;
	char			*conv_str;

	int				field_width;
	int				precision;
	
	char			whitespace;


	int	temp;
}					t_pf;

typedef void	(*funcPtr)(t_pf*);

int		ft_printf(char *str, ...);
int		is_modifier(char letter);

void    parse_modifiers(t_pf *obj);
void    parse_flags(t_pf *obj);
void    conversion_launchdeck(t_pf *obj);
void    parse_conversion(t_pf *obj);

void    create_functions_array(funcPtr *func);
void    create_base_table(int *tab);

void    four_oh_four(t_pf *obj);

void    put_char(t_pf *obj);
void    put_str(t_pf *obj);
void    put_ptr(t_pf *obj);
void    put_nbr(t_pf *obj);
void    put_nbr_base(t_pf *obj);


char	*ft_strnew(int size);
int		ft_atoi(char *nptr);
void	ft_putchar(char c);
int		ft_strchr(char *str, char c);
int		ft_strlen(char *str);
void    *ft_memset(void *b, int c, unsigned int size);

char	*ft_strcpy(char *dst, char *src);
void	convert_to_base_str(t_pf *obj, int num, char *str);

void    check_integers(t_pf *obj);
void    check_precision(t_pf *obj);

char	is_integer(char possible_integer);
int     is_period(char letter);
int     is_star(char letter);
int     is_zero(char letter);
int     is_minus(char letter);
void    *ft_memset(void *b, int c, unsigned int size);

void    int_to_str(t_pf *obj, int num, char *str);



#endif

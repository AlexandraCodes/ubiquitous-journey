/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 22:35:16 by alecasti          #+#    #+#             */
/*   Updated: 2021/05/20 16:50:34 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

void	exec_identifier(t_details deets, char letter, va_list arg, int *width)
{
	//char    type_char;
	char	*type_str;
	int     type_int;
	void	*type_ptr;
	/*
	   if (letter == 'c')
	   {
	   type_char = va_arg(arg, int);
	   ft_putchar(type_char);
	   }
	   */
	if ((letter == 's') && (type_str = va_arg(arg, char *)))
		print_str(deets, type_str, width);
	//if (letter == 'p')
	//    print_ptr();
	//    if (letter == 'd' /*|| letter == 'i'*/)
	/*    {
		  type_int = va_arg(arg, int);
		  print_dec(deets, type_int);
		  }
		  */
	if (letter == 'p' && (type_ptr = va_arg(arg, void *)))
		print_ptr(type_ptr);

	if ((letter == 'd' || letter == 'i' || letter == 'u' || letter == 'x' || letter == 'X') && (type_int = va_arg(arg, int)))
		print_hex(deets, type_int, width, letter);
	//if ((letter == 'x' || letter == 'X') && (type_int = va_arg(arg, int)))
	//	print_hex(deets, type_int, width, letter);
}

void	print_ptr(void *ptr)
{
	char *str;
	int		i;

	str = ft_strnew(50);
	i = (int)ptr;
	convert_to_base_str(i, str, 16, 'x');
}



void	print_hex(t_details details, int num, int *width, char type)
{
	char	*hex;

	// why 12?
	hex = ft_strnew(12);
	if (type == 'x' || type == 'X')
		convert_to_base_str(num, hex, 16, type);
	if (type == 'd' || type == 'i' || type == 'u')
		convert_to_base_str(num, hex, 10, type);

	printf("this is hex value -- %s\n", hex);

	int		*h;
	t_details	det;

	h = width;
	det = details;
}



/////////////////////////////////////////////////////////
/*
 *
 *  EVERYTHING BELOW HERE IS FOR PRINT_STRING EXECUTION 
 *
 */
/////////////////////////////////////////////////////////

void	print_str(t_details details, char *str, int *width)
{
	int		len;
	int		i;
	int		min_space;
	int		min_word;

	i = -1;
	len = ft_strlen(str);
	min_word = minimum_word_length(width[1], len);
	min_space = minimum_space_size(width[0], min_word);
	(!details.minus) && print_whitespace(min_space - min_word);
	print_substr(str, min_word);
	(details.minus) && print_whitespace(min_space - min_word);
}

void	print_substr(char *str, int len)
{
	int		i;
	char	*temp;

	i = -1;
	temp = ft_strnew(len);
	temp[len] = '\0';
	while (++i < len)
		temp[i] = str[i];
	write(1, temp, (len + 1));
	free(temp);
}

int		print_whitespace(int len)
{
	int		i;

	i = -1;
	while (++i < len)
		write(1, " ", 1);
	return (1);
}

int		minimum_word_length(int min_len, int len)
{
	if ((min_len < len) && (min_len >= 0))
		return (min_len);
	return (len);
}

int		minimum_space_size(int min_space, int min_len)
{
	if ((min_space >= min_len) && (min_space >= 0))
		return (min_space);
	return (min_len);
}

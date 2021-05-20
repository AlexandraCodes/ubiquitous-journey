/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: alecasti <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/04/03 21:20:31 by alecasti		  #+#	#+#			 */
/*   Updated: 2021/05/18 16:56:36 by alecasti         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		is_integer(char possible_integer)
{
	if (possible_integer > 47 && possible_integer < 58)
		return (1);
	return (0);
}

int		is_identifier(char letter)
{
	char	*identifiers;

	identifiers = "cspdiuxX";
	if (ft_strchr(identifiers, letter))
		return (1);
	return (0);
}


/*
 * 0 -- FLAG
 * 1 -- MIN/MAX
 * 2 -- PERIOD
 */


int		ft_printf(char *str, ...)
{
	va_list			list;
	int				i;
	t_details		details;

	int				j;
	int				k;

	char			*zone;
	char			*max;

	int				width[2];

	width[0] = -1;
	width[1] = -1;
	i = 0;
	va_start(list, str);
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			//was checking this 
			if (!(is_identifier(str[i])))
			{
				while (is_flag(str[i]))
				{
					if (is_minus(str[i]))
						details.minus = 1;
					if (is_zero(str[i]))
						details.zero = 1;
					i++;
				}
				// printf("WHAT IS DETAILS.FLAG --> %d\n\n", details.flag);
				// printf("WHAT IS DETAILS.MINUS --> %d\n\n", details.minus);
				// printf("WHAT IS DETAILS.ZERO --> %d\n\n", details.zero);
				//
				//
				// j = nbr_size
				if (is_integer(str[i]) || is_star(str[i]))
				{
					details.min = 1;
					if (is_star(str[i]))
						width[0] = va_arg(list, int);
					if (is_integer(str[i]))
					{
						j = 0;
						while (is_integer(str[i + j]))
							j++;
						zone = ft_strnew(j);
						k = 0;
						while (k < j)
						{
							zone[k] = str[i];
							k++;
							i++;
						}
						width[0] = ft_atoi(zone);
					}
				}
				// printf("this is WIDTH[1] aka MIN -- %d\nthis is WIDTH[2] aka MAX -- %d\n", width[0], width[1]);
				//
				//
				//
				// details.star = is_star(str[i]);
				//
				//
				//

				//  printf("\n\nthis is where STR[I] is -- %c\n\n", str[i]);

				if (is_period(str[i]))
				{
					details.period = 1;
					i++;
					if (is_identifier(str[i]))
						width[1] = 0;
					if (is_integer(str[i]))
					{
						details.max = 1;
						j = 0;
						while (is_integer(str[i + j]))
							j++;
						max = ft_strnew(j);
						k = 0;
						while (k < j)
						{
							max[k] = str[i];
							k++;
							i++;
						}
						width[1] = ft_atoi(max);
					}
					if (is_star(str[i]))
						width[1] = va_arg(list, int);
					//  printf("this is WIDTH[1] aka MIN -- %d\nthis is WIDTH[2] aka MAX -- %d\n", width[0], width[1]);

				}

				// send value to printing/printf

			}

			if (is_identifier(str[i]))
			{
				exec_identifier(details, str[i], list, width);
				details.min = 0;
				details.max = 0;
				details.minus = 0;
				details.zero = 0;
				details.period = 0;
				i++;
			}
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (1);
}


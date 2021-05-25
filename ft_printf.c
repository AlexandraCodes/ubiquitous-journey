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



int		is_modifier(char letter)
{
	char	*modifiers;
	int		ret;

	modifiers = "-0*";
	ret = ft_strchr(modifiers, letter);
	return (ret);
}


/*
 * 0 -- FLAG
 * 1 -- MIN/MAX
 * 2 -- PERIOD
 */


int		ft_printf(char *str, ...)
{
	t_pf		deets;
	int				i;

	i = 0;
	// ft_memset(&deets, 0, sizeof(deets));
	deets.str = str;
	va_start(deets.list, str);
	while (*deets.str && deets.str[i])
	{
		if (*deets.str == '%')
		{
			++deets.str;
			parse_conversion(&deets);
			// if parse_conversion == -1 then go to else
		}
		else
			write(1, (deets.str)++, 1);
	}

	return (1);
}


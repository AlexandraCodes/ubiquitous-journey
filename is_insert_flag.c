/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_insert_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:14:42 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/04 20:30:42 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     is_minus(char letter)
{
    if (letter == '-')
        return 1;
    return 0;
}

int     is_zero(char letter)
{
    if (letter == '0')
        return 1;
    return 0;
}

int     is_star(char letter)
{
    if (letter == '*')
        return 1;
    return 0;
}

int     is_period(char letter)
{
    if (letter == '.')
        return 1;
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_insert_flag_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:14:42 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/04 20:33:43 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     is_plus(char letter)
{
    if (letter == '+')
        return 1;
    return 0;
}

int     is_pound(char letter)
{
    if (letter == '#')
        return 1;
    return 0;
}

int     is_space(char letter)
{
    if (letter == ' ')
        return 1;
    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 20:29:15 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/21 13:41:59 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void    parse_modifiers(t_pf *obj)
{
    while ((obj->temp = is_modifier(*obj->str)) > -1 && ++obj->str)
        obj->flags |= (1 << obj->temp);
    if (!(obj->flags & F_STAR) && (is_integer(*obj->str)) != '-')
        check_integers(obj);

    // if ((F_SPACE & obj->flags) && (F_PLUS & obj->flags))
    //     obj->flags &= ~F_SPACE;
    
    if (obj->flags & F_STAR)
    {
        obj->flags &= ~F_STAR;
        obj->temp = va_arg(obj->list, int);
        // if neg number passed to va_list
        if (obj->temp < 0)
        {
            obj->flags |= F_MINUS;
            obj->temp = -obj->temp;
        }
        obj->field_width = obj->temp;
        obj->flags |= F_FWIDTH;
    }
    // minus overrides a zero if both given
    // double && left-most check for true -- exit otherwise
    if ((F_ZERO & obj->flags) && (F_MINUS & obj->flags))
        obj->flags &= ~F_ZERO;

    check_precision(obj);

    // if (obj->flags & F_PERIOD)
    // {
    //     while (is_star(*(obj->str)) && ++obj->str)
    //         obj->flags |= F_STAR;
    //     if (!(obj->flags & F_STAR) && (is_integer(*obj->str)))
    //         check_integers(obj);
    // }
    
    if (F_STAR & obj->flags)
    {
        // printf("this is deets.str -- %s\n\n", obj->conv_str);
        obj->flags &= ~F_STAR;
        obj->temp = va_arg(obj->list, int);
        // if neg number passed to va_list
        if (obj->temp < 0)
            obj->temp = -obj->temp;
        obj->precision = obj->temp;
    }
}

void    parse_flags(t_pf *obj)
{
    char *str;
    int     i;
    int     j;

    i = 0;
    j = 0;

    if (obj->item == 's' || obj->item == 'c')
    {
        if ((obj->precision < obj->conv_len) && (obj->precision >= 0))
            obj->precision = obj->precision;
        else
            obj->precision = obj->conv_len;
    }

    if (obj->item == 'd' || obj->item == 'x' || obj->item == 'X')
    {
        if (obj->precision < obj->conv_len)
            obj->precision = obj->conv_len;
        // if (obj->field_width < obj->precision)
        //     obj->field_width = obj->precision;
    }

    // if (obj->flags & F_FWIDTH)
    // {
    if ((obj->field_width >= obj->precision) && (obj->field_width >= 0))
        obj->field_width = obj->field_width;
    else
        obj->field_width = obj->precision;
    // }

    // printf("\nthis is int -- >  %d::\n", obj->precision);
    // printf("\nthis is int -- >  %d::\n", obj->field_width);


    
    // printf("\nthis is int -- >  %d::\n", obj->precision);
    // printf("\nthis is int -- >  %d::\n", obj->field_width);

    str = ft_strnew(obj->field_width);
    // printf("\nthis is conv_len -- >  %c::\n", obj->whitespace);

    if ((obj->flags & F_ZERO) && (obj->item == 'd' || obj->item == 'x' || obj->item == 'X')) 
        obj->whitespace = '0';
    // printf("\nthis is conv_len -- >  %c::\n", obj->whitespace);

    if (obj->flags & F_MINUS)
    {
        while (i < obj->precision)
        {
            str[i] = obj->conv_str[i];
            i++;
        }
        while (i < obj->field_width)
        {
            str[i] = obj->whitespace;
            i++;
        }
    }
    else
    {
        // i = obj->field_width - obj->precision;
        if (obj->item == 's')
        {
            while (i < (obj->field_width - obj->precision))
            {
                str[i] = obj->whitespace;
                i++;
            }
        }
        else
        {
            while (i < (obj->field_width - obj->conv_len))
            {
                str[i] = obj->whitespace;
                i++;
            }
        }
        while (i < obj->field_width)
        {
            // *obj->conv_str++;
            str[i] = obj->conv_str[j];
            i++;
            j++;
        }
    }
    obj->str++;
    write(1, str, i);
    // printf("\nthis is int -- >  %d::\n", i);
    // printf("\nthis is string -- >  %s::\n", str);
    // printf("\nthis is string -- >  %s::\n", obj->conv_str);


    // if min, max, precision, etc...
    // left align, right, zeros, and spaces
    // printf("this is deets.str -- %s\n\n", obj->conv_str);
    // printf("this is obj->flags -- %d\n\n", obj->flags);

    // printf("Here we parse flags because they were found -- %d", obj->flags);

}

void    conversion_launchdeck(t_pf *obj)
{
    funcPtr     func[256];
    int         table[256];

    create_functions_array(func);
    create_base_table(table);
    if (obj->item == 'X')
        obj->flags |= F_CAPITAL;
    
    obj->base = table[(unsigned char)obj->item];
    func[(unsigned char)obj->item](obj);
    if (obj->flags & F_CONVSET)
        parse_flags(obj);
}

void    parse_conversion(t_pf *obj)
{
    obj->flags = 0;
    obj->whitespace = ' ';
    obj->field_width = -1;

    parse_modifiers(obj);

    obj->item = *obj->str;

    conversion_launchdeck(obj);
}
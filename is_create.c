#include "printf.h"

void    check_integers(t_pf *obj)
{
    int     i;
    char    c;
    char    *str;

    i = 0;
    str = ft_strnew(12);
    while ((c = is_integer(*obj->str)) != '-' && ++obj->str)
    {
        str[i] = c;
        i++;
    }
    str[i] = '\0';
    i = ft_atoi(str);
    // printf("this is check ints -- %d\n", i);
    if (obj->flags & F_PERIOD)
        obj->precision = i;
    else
        obj->field_width = i;
    free(str);
}

void    check_precision(t_pf *obj)
{
    char    c;

    while (is_period(*obj->str) && ++obj->str)
        obj->flags |= F_PERIOD;
    c = is_integer(*obj->str);
    if ((obj->flags & F_PERIOD) && (c != '-'))
    {
        while (is_star(*(obj->str)) && ++obj->str)
                obj->flags |= F_STAR;
        check_integers(obj);
    }
    else
        obj->precision = -1;
}




void    create_functions_array(funcPtr *func)
{
    int     i;

    i = 0;
    while (i < 256)
        func[i++] = &four_oh_four;
    func['c'] = &put_char;
    func['s'] = &put_str;
    func['p'] = &put_ptr;
    func['d'] = &put_nbr;
    func['i'] = &put_nbr;
    func['u'] = &put_nbr_base;
    func['x'] = &put_nbr_base;
    func['X'] = &put_nbr_base;
    // func['n'] = &put_;
    // func['f'] = &put_;
    // func['g'] = &put_;
    // func['e'] = &put_;
}

void    create_base_table(int *tab)
{
    ft_memset(tab, 0, sizeof(*tab));
    tab['o'] = 8;
    tab['u'] = 10;
    tab['x'] = 16;
    tab['X'] = 16;
}
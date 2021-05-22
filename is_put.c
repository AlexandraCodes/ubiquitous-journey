#include "printf.h"

void    put_char(t_pf *obj)
{
    int    c;

    c = va_arg(obj->list, int);
    if (!c)
        return ;
    obj->conv_str = ft_strnew(1);
    obj->conv_str[0] = (char)c;
    obj->flags |= F_CONVSET;
}

void    put_str(t_pf *obj)
{
    char    *str;

    str = va_arg(obj->list, char *);
    if (!str)
        return ;
    obj->conv_len = ft_strlen(str);
    obj->conv_str = ft_strnew(obj->conv_len);
    ft_strcpy(obj->conv_str, str);
    obj->flags |= F_CONVSET;
}

void    put_ptr(t_pf *obj)
{
    printf("this is put ptr -- %c\n\n", obj->item);
}

void    put_nbr(t_pf *obj)
{
    int     i;
    char    *str;

    i = va_arg(obj->list, int);
    str = ft_strnew(13);
    int_to_str(obj, i, str);
    obj->conv_str = ft_strnew(obj->conv_len);
    ft_strcpy(obj->conv_str, str);
    free(str);
    obj->flags |= F_CONVSET;
}

void    put_nbr_base(t_pf *obj)
{
    int     i;
    char    *str;

    i = va_arg(obj->list, int);
    str = ft_strnew(12);
    convert_to_base_str(obj, i, str);
    obj->conv_str = ft_strnew(obj->conv_len);
    ft_strcpy(obj->conv_str, str);
    free(str);
    obj->flags |= F_CONVSET;
}
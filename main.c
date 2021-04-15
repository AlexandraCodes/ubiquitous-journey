/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:41:49 by alecasti          #+#    #+#             */
/*   Updated: 2021/04/15 02:22:29 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int     main(int ac, char *av[])
{
    int ret;

    printf("%d %s\n\n", ac, av[0]);
    ret = ft_printf("MY_PRINTF --- \n%10.15s\n\n", "Hello, World!");
    printf("PRINTF --- is supposed to print - - 0 8 3 9 8 . 2 0 3 9 8 1 2 3\n");

    printf("=====================================\n");
    
    ft_printf(":%s:  s\n", "Hello, world!");
	ft_printf(":%15s:  15s\n", "Hello, world!");
	ft_printf(":%.10s:  .10s\n", "Hello, world!");
	ft_printf(":%-10s:  -10s\n", "Hello, world!");
	ft_printf(":%-15s:  -15s\n", "Hello, world!");
    ft_printf(":%-.30s:  -.30s\n", "Hello, world!");
	ft_printf(":%-.10s:  -.10s\n", "Hello, world!");
	ft_printf(":%3.30s:  3.30s\n", "Hello, world!");
	ft_printf(":%15.30s:  15.30s\n", "Hello, world!");
	ft_printf(":%-35.20s:  -35.20s\n", "Hello, world!");

    printf("=====================================\n");

    printf(":%s:  s\n", "Hello, world!");
	printf(":%15s:  15s\n", "Hello, world!");
	printf(":%.10s:  .10s\n", "Hello, world!");
	printf(":%-10s:  -10s\n", "Hello, world!");
	printf(":%-15s:  -15s\n", "Hello, world!");
    printf(":%-.30s:  -.30s\n", "Hello, world!");
	printf(":%-.10s:  -.10s\n", "Hello, world!");
	printf(":%3.30s:  3.30s\n", "Hello, world!");
	printf(":%15.30s:  15.30s\n", "Hello, world!");
	printf(":%-35.20s:  -35.20s\n", "Hello, world!");

    return 0;
}

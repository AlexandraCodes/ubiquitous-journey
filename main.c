/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:41:49 by alecasti          #+#    #+#             */
/*   Updated: 2021/05/24 22:01:54 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int     main(int ac, char *av[])
{
    // int ret;

    printf("%d %s\n\n", ac, av[0]);
	
    printf("=====================================\n");
	
	// int val = -1991687980;
	int val = 1;
	// // char pt[] = "asd";
	// char *str = "hellrhellr";
	// char	c = 'A';

	// printf("\033[0;31m");
	// ft_printf("THIS IS YOU -- %*.2d\n", 5, val);
	// printf("\033[0m ya ya ya\n----\n");

	// // ft_printf(":%x:  x\n", val);
	// // ft_printf(":%d:		d\n", val);
	// // ft_printf(":%p:		p\n", pt);

	// ft_printf(":%-15x:  x\n", val);
	// ft_printf(":%-15X:  X\n", val);
	// ft_printf(":%-15s:  s\n", str);
	// ft_printf(":%-15c:  c\n", c);
	// ft_printf(":%-15d:  d\n", val);

	// printf("\n");

	// ft_printf(":%15x:  x\n", val);
	// ft_printf(":%15X:  X\n", val);
	// ft_printf(":%15s:  s\n", str);
	// ft_printf(":%15c:  c\n", c);
	// ft_printf(":%15d:  d\n", val);

    // printf("=====================================\n");

	// printf(":%-15x:  x\n", val);
	// printf(":%-15X:  X\n", val);
	// printf(":%-15s:  s\n", str);
	// printf(":%-15c:  c\n", c);
	// printf(":%-15d:  d\n", val);

	printf("\n");

    printf("=====================================\n");
	printf("========== TESTING FOR -- d =========\n");
    printf("=====================================\n");
	printf(":d:\n");
	printf("\nmy printf -->");
	ft_printf("|%d|", val);
	printf("\npc printf --> |%d|\n", val);

	printf(":-d:\n");
	printf("\nmy printf --> |");
	ft_printf("%-d", val);
	printf("|");
	printf("\npc printf --> |%-d|\n", val);

	printf(":*d:\n");
	printf("\nmy printf --> |");
	ft_printf("%*d", 5, val);
	printf("|");
	printf("\npc printf --> |%*d|\n", 5, val);

	printf(":0d:\n");
	printf("\nmy printf --> |");
	ft_printf("%0d", val);
	printf("|");
	printf("\npc printf --> |%0d|\n", val);

	printf(":-0d:\n");
	printf("\nmy printf --> |");
	ft_printf("%-d", val);
	printf("|");
	printf("\npc printf --> |%-d|\n", val);

	// printf(":0-d:\n");
	// printf("\nmy printf --> |");
	// ft_printf("%0-d", val);
	// printf("|");
	// printf("\npc printf --> |%0-d|\n", val);

	// printf("\nmy printf --> |");
	// printf("\npc printf --> |%d");


	// printf(":%15x:  x\n", val);
	// printf(":%15X:  X\n", val);
	// printf(":%15s:  s\n", str);
	// printf(":%15c:  c\n", c);
	// printf(":%15d:  d\n", val);
	/*
	printf(":%15x:  15x\n", val);
	printf(":%.10x:  .10x\n", val);
	printf(":%-10x:  -10x\n", val);
	printf(":%-15x:  -15x\n", val);
    printf(":%-.30x:  -.30x\n", val);
	printf(":%-.10x:  -.10x\n", val);
	printf(":%3.10x:  3.10x\n", val);
	printf(":%3.30x:  3.30x\n", val);
	printf(":%15.30x:  15.30x\n", val);
	printf(":%-35.10x:  -35.10x\n", val);
    */
    // printf("=====================================\n");
	
	// ret = ft_printf("MY_PRINTF --- \n%10.15s\n\n", "Hello, World!");
    // printf("PRINTF --- is supposed to print - - 0 8 3 9 8 . 2 0 3 9 8 1 2 3\n");

    // printf("=====================================\n");

	// printf(":%0*d:  0*d\n", 15, 5);
	// printf(":%-*d:  0-*d\n", 15, 5);
	// printf(":%*.*d:  *.*d\n", 15, -5, 5231442);
	// printf(":%-*%:  -(-15)d\n", 5);
    
    // ft_printf(":%s:  s\n", "Hello, world!");
	// ft_printf(":%15s:  15s\n", "Hello, world!");
	// ft_printf(":%.10s:  .10s\n", "Hello, world!");
	// ft_printf(":%-10s:  -10s\n", "Hello, world!");
	// ft_printf(":%-15s:  -15s\n", "Hello, world!");
    // ft_printf(":%-.30s:  -.30s\n", "Hello, world!");
	// ft_printf(":%-.10s:  -.10s\n", "Hello, world!");
	// ft_printf(":%3.30s:  3.30s\n", "Hello, world!");
	// ft_printf(":%15.30s:  15.30s\n", "Hello, world!");
	// ft_printf(":%-35.20s:  -35.20s\n", "Hello, world!");

    // printf("=====================================\n");

    // printf(":%s:  s\n", "Hello, world!");
	// printf(":%15s:  15s\n", "Hello, world!");
	// printf(":%.10s:  .10s\n", "Hello, world!");
	// printf(":%-10s:  -10s\n", "Hello, world!");
	// printf(":%-15s:  -15s\n", "Hello, world!");
    // printf(":%-.30s:  -.30s\n", "Hello, world!");
	// printf(":%-.10s:  -.10s\n", "Hello, world!");
	// printf(":%3.30s:  3.30s\n", "Hello, world!");
	// printf(":%15.30s:  15.30s\n", "Hello, world!");
	// printf(":%-35.20s:  -35.20s\n", "Hello, world!");

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:00:09 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/01 19:13:42 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<stdio.h>
#include<limits.h>
 
int	main()
{
	//int	c;
	//char	*s;

	//c = 128;
	//s = "0";


	ft_printf("%%%%%%");
    ft_printf("Tests para tipo %%d %%i \n");
	ft_printf("%d\n", 0);
	ft_printf("%d\n", -10);
	ft_printf("%d\n", -200000);
	ft_printf("%d\n", -6000023);
	ft_printf("%d\n", 10);
	ft_printf("%d\n", 10000);
	ft_printf("%d\n", 100023);
	ft_printf("INTMAX: %d\n", INT_MAX);
	ft_printf("INTMIN: %d\n", INT_MIN);
	ft_printf("dgs%dxx\n", 10);
	ft_printf("%d%dd%d\n", 1, 2, -3);
	ft_printf("%i\n", 0);
	ft_printf("%i\n", -10);
	ft_printf("%i\n", -200000);
	ft_printf("%i\n", -6000023);
	ft_printf("%i\n", 10);
	ft_printf("%i\n", 10000);
	ft_printf("%i\n", 100023);
	ft_printf("INTMAX: %i\n", INT_MAX);
	ft_printf("INTMIN: %i\n", INT_MIN);
	ft_printf("dgs%ixx\n", 10);
	ft_printf("%i%ii%i\n", 1, 2, -3);
	printf("\n");
	ft_printf("Tests para tipo %%x \n");
	ft_printf("%x\n", 42);
	ft_printf("before %x after\n", 42);
	ft_printf("%x%x%x%x%x\n", 1, 100, 999, 42, 999988888);
	ft_printf("a%xb%xc%xd\n", 0, 55555, 100000);
	ft_printf("%x, %x\n", 0, 2147483647);
	printf("\n");
	ft_printf("Tests para tipo %%X \n");
	ft_printf("%X\n", 42);
	ft_printf("before %X after\n", 42);
	ft_printf("%X%X%X%X%X\n", 1, 100, 999, 42, 999988888);
	ft_printf("a%Xb%Xc%Xd\n", 0, 55555, 100000);
	ft_printf("%X, %X\n", 0, UINT_MAX);
	return (0);
}
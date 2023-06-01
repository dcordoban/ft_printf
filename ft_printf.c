/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:31:22 by david             #+#    #+#             */
/*   Updated: 2023/06/01 13:12:39 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<limits.h>

static int	ft_eval_format(const char format, va_list args)
{
	int	len;

	len = 0;
	if (format == '%')
		len = ft_print_char('%');
	else if (format == 'c')
		len = ft_print_char((char) va_arg(args, int));
	else if (format == 's')
		len = ft_prints(va_arg(args, char *));
	else if (format == 'u')
		len = ft_print_u(va_arg(args, unsigned int));
	else if (format == 'd' || format == 'i')
		len = ft_printnb(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		len = ft_print_hex(format, va_arg(args, unsigned int));

	return (len);
}


static int	ft_check_format(const char *format, va_list args, int result)
{
	int	i;
	int	str;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			str = ft_eval_format(format[i + 1], args);
			if (str == -1)
				return (-1);
			result = i + str;
			i++;
		}
		else
		{
			if (write(1, &format[i], 1) != 1)
				return (-1);
			result++;
		}
		i++;
	}
	return (result);
}


int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_check_format(format, args, 0);
	va_end(args);
	return (result);
}

int	main()
{
	//int	c;
	//char	*s;

	//c = 128;
	//s = "0";


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

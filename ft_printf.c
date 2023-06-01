/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:31:22 by david             #+#    #+#             */
/*   Updated: 2023/06/01 19:17:42 by dcordoba         ###   ########.fr       */
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
	else if (format == 'p')
		len = ft_print_p(va_arg(args, void *));
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
			result += str;
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

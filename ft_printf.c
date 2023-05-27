/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:31:22 by david             #+#    #+#             */
/*   Updated: 2023/05/27 20:29:20 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_eval_format(va_list args, char format)
{
	unsigned int	len;
	
	len = 0;
	if (format == 'c')
		len = ft_print_char((char) va_arg(args, int));
	if (format == 's')
		len = ft_prints(va_arg(args, char *));
	/*if (*format == 'd' || *format == 'i')
		f += ft_printnb(va_arg(args, int));*/
	//printf("len: %i\n", len);
	return (len);
}


int	ft_check_format(const char *format, va_list args, int result)
{
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			printf("i: %i\n", i);
			result = ft_eval_format(args, format[i + 1]);
		}
		else
			result += write(1, &format[i], 1);
	}
	printf("result check format b: %i\n", result);
	printf("result check format i: %i\n", i);
	return (result);
}


int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		result;

	
	va_start(args, format);
	//parse format && print
	result = ft_check_format(format, args, 0);
	if ( result == -1)
	{
		va_end(args);
		return (-1);

	}
	va_end(args);
	//printf("result:%i", result);
	return (result);
}

int	main()
{
	//int	*c;
	char	*s;

	//c = 'a';
	s = "david";

	//int test = 93;

	//printf("test vale: %i", test)

	ft_printf("david%s");
	
	//printf("My func: %d\n", ft_printf(s));

	//printf("Function C: %c\n", &c);
	//printf("1");

	return (0);
}

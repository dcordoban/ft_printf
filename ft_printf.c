/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 23:31:22 by david             #+#    #+#             */
/*   Updated: 2023/05/25 23:18:15 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_eval_format(va_list args, int *format, int f)
{
	if (*format == 'c')
		f += ft_printc((char) va_arg(args, int));
	if (*format == 's')
		f += ft_prints(va_arg(args, char *));
	if (*format == 'd' || *format == 'i')
		f += ft_printnb(va_arg(args, int));
	return (f);
}


int	ft_check_format(char *format, va_list args, int *result)
{
	int	i;

	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			i = ft_eval_format(args, format, i + 1);
		else
			result += write(1, &format[i], 1);
	}
	return (result);
}


int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		result;

	result = 0;
	va_start(args, format);
	//parse format && print
	if (ft_eval_format(*format, args, &result) == -1)
	{
		va_end(args);
		return (-1);

	}
	va_end(args);
	return (result);
}

int	main()
{
	char	c;
	char	*s;

	c = 'a';
	s = "my name is david";

	ft_printf('a');
	ft_printf(s);

	printf("Function C: %c\n", c);
	printf("Function S: %s\n", s);

	return (0);
}

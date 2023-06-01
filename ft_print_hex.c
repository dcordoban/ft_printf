/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:37:15 by david             #+#    #+#             */
/*   Updated: 2023/06/01 18:56:03 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int b)
{
	size_t	counter;

	counter = 0;
	if (b == 0)
		counter++;
	while (b)
	{
		b = b / 16;
		counter++;
	}
	return (counter);
}

int	ft_print_hex(const char format, unsigned int nb)
{
	char	*hex;
	char	*ptr;
	int		i;
	int		counter;

	if (format == 'x')
		hex = "0123456789abcdef";
	else if (format == 'X')
		hex = "0123456789ABCDEF";
	i = count_digits(nb);
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (-1);
	ptr[i] = '\0';
	i--;
	while (nb >= 0 && i >= 0)
	{
		ptr[i--] = hex[nb % 16];
		nb = nb / 16;
	}
	counter = ft_prints(ptr);
	free(ptr);
	return (counter);
}

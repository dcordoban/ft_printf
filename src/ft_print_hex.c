/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:37:15 by david             #+#    #+#             */
/*   Updated: 2023/06/11 17:44:46 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	count_digits(unsigned long int b)
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

int	ft_print_hex(const char format, unsigned long int nb, int *len)
{
	char	*hex_base;
	char	*tmp;
	int		i;

	if (format == 'x')
		hex_base = "0123456789abcdef";
	else if (format == 'X')
		hex_base = "0123456789ABCDEF";
	i = count_digits(nb);
	tmp = (char *)malloc((i + 1) * sizeof(char));
	if (!tmp)
		return (-1);
	tmp[i] = '\0';
	i--;
	while (nb && i >= 0)
	{
		tmp[i--] = hex_base[nb % 16];
		nb = nb / 16;
	}
	*len += ft_prints(tmp);
	free(tmp);
	return (*len);
}

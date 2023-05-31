/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:06:34 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/31 22:44:08 by dcordoba         ###   ########.fr       */
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

int	ft_print_hex_lower(unsigned int nb)
{
	char	*hex;
	char	*ptr;
	int		i;

	hex = "0123456789abcdef";
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
	return (ft_prints(ptr));
}


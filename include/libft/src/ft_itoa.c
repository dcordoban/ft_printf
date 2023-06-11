/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:59:57 by david             #+#    #+#             */
/*   Updated: 2023/05/18 18:52:04 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_decimal_to_ascii(long nb, char *string, int digits)
{
	int	mod;
	int	slots;

	slots = digits - 1;
	if (nb == 0)
		string[slots] = nb + '0';
	while (nb > 0)
	{
		mod = nb % 10;
		string[slots--] = mod + '0';
		nb = nb / 10;
	}
	string[digits] = '\0';
	return (string);
}

static int	count_digits(int b)
{
	size_t	counter;

	counter = 0;
	if (b < 0 || b == 0)
		counter += 1;
	while (b)
	{
		b = b / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int b)
{
	char	*string;
	int		digits;
	long	nbr;

	nbr = b;
	if (nbr < 0)
		nbr = -nbr;
	digits = count_digits(b);
	string = (char *)malloc((digits + 1) * sizeof(char));
	if (!(string))
		return (0);
	string = ft_decimal_to_ascii(nbr, string, digits);
	if (b < 0)
		ft_memset(string, '-', 1);
	return (string);
}

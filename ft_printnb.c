/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:57:20 by david             #+#    #+#             */
/*   Updated: 2023/06/01 17:17:37 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnb(int n)
{
	int	counter;

	counter = 0;
	if (n == -2147483648)
	{
		counter += ft_print_char('-');
		counter += ft_print_char('2');
		ft_printnb(147483648);
		return (counter);
	}
	if (n < 0)
	{
		counter += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_printnb(n / 10);
		n = n % 10;
	}
	if (n < 10)
		counter += ft_print_char('0' + n);
	return (counter);
}

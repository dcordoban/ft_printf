/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:57:20 by david             #+#    #+#             */
/*   Updated: 2023/06/04 09:53:14 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_char(char c, int *len)
{
	if (write(1, &c, 1) == 1)
		*len += 1;
	else
		*len = -1;
	return (*len);
}

void	*ft_printnb(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_put_char('-', len);
		ft_put_char('2', len);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_put_char('-', len);
		n = -n;
	}
	if (n >= 10)
	{
		ft_printnb(n / 10, len);
		n = n % 10;
	}
	if (n < 10)
		ft_put_char('0' + n, len);
}

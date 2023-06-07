/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:57:20 by david             #+#    #+#             */
/*   Updated: 2023/06/07 20:07:36 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_char(char c, int len)
{
	if (write(1, &c, 1) == 1)
		len += 1;
	else
		return (-1);
	return (len);
}

static int	ft_int_max(int len)
{
	if (ft_put_char('-', len) == -1)
		return (-1);
	len++;
	if (ft_put_char('2', len) == -1)
		return (-1);
	len++;
	len = ft_printnb(147483648, len);
	return (len);
}

int	ft_printnb(int n, int len)
{	
	if (n == -2147483648)
		return (ft_int_max(len));
	if (n < 0)
	{
		len = ft_put_char('-', len);
		if (len == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		len = ft_printnb(n / 10, len);
		if (len == -1)
			return (-1);
		n = n % 10;
	}
	if (n < 10)
	{
		len = ft_put_char('0' + n, len);
		if (len == -1)
			return (-1);
	}
	return (len);
}

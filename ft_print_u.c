/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:57:11 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/07 19:27:29 by dcordoba         ###   ########.fr       */
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

int	ft_print_u(unsigned int nb, int len)
{
	if (nb > 9)
	{
		len = ft_print_u(nb / 10, len);
		if (len == -1)
			return (-1);
		nb = nb % 10;
	}
	if (nb <= 9)
	{
		len = ft_put_char('0' + nb, len);
		if (len == -1)
			return (-1);
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:57:11 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/03 21:36:17 by dcordoba         ###   ########.fr       */
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

void	*ft_print_u(unsigned int nb, int *len)
{
	if (nb > 9)
	{
		ft_print_u(nb / 10, len);
		nb = nb % 10;
	}
	if (nb <= 9)
	{
		ft_put_char('0' + nb, len);
	}
}

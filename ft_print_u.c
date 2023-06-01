/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:57:11 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/01 20:19:20 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_char(char c, int count)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	count += 1;
	return (count);
}

int	ft_print_u(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb > 9)
	{
		counter++;
		ft_print_u(nb / 10);
		nb = nb % 10;
	}
	if (nb <= 9)
	{
		if (ft_put_char('0' + nb, counter) != 1)
			return (-1);
	}
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:57:11 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/28 21:16:52 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include<limits.h>

int	ft_print_u(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb > 9)
	{
		ft_print_u(nb / 10);
		nb = nb % 10;
	}
	if (nb <= 9)
	{
		if (ft_print_char('0' + nb) != 1)
			return (-1);
		counter++;
	}
	return (counter);
}

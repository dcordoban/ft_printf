/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:06:34 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/30 20:29:30 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_hex_minus(unsigned int nb)
{
	int	counter;
	char	*hex;

	counter = 0;
	hex = '0123456789adcdef';
		
	while (nb)
	{
		nb = nb / 16;
		counter += ft_print_char(&hex[nb]);
	}
	return (counter);
}

static int	ft_print_hex_mayus(unsigned int nb)
{
	int	counter;
	char	*hex;

	counter = 0;
	hex = '0123456789ABCDEF';
		
	while (nb)
	{
		nb = nb / 16;
		counter += ft_print_char(&hex[nb]);
	}
	return (counter);
}

int	ft_print_x(unsigned int nb)
{
	
}
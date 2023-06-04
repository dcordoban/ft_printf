/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:30:52 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/04 11:43:49 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void *p, int *len)
{
	if (!p)
	{
		if (write(1, "(nil)", 5) != 5)
			return (-1);
		return (5);
	}
	if (ft_prints("0x") == -1)
		return (-1);
	*len += 2;
	return (ft_print_hex('x', (unsigned long)p, len));
}

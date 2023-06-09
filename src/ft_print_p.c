/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:30:52 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/11 17:44:37 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_p(void *p, int *len)
{
	if (ft_prints("0x") == -1)
		return (-1);
	*len += 2;
	return (ft_print_hex('x', (unsigned long)p, len));
}

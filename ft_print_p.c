/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:30:52 by dcordoba          #+#    #+#             */
/*   Updated: 2023/06/01 16:53:53 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(void	*p)
{
	unsigned long	ptr;
	int					counter;
	char	*hex;

	ptr = (unsigned long long)p;
	hex = "0123456789abcdef";
	counter = 0;
	if (!ptr)
		return (-1);
	if (ft_prints("0x2") != 3)
		return (-1);
	while (ptr)
	{
		counter += ft_print_char(hex[ptr % 16]);
		ptr++;
	}
	return (counter);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 19:35:44 by david             #+#    #+#             */
/*   Updated: 2023/06/11 17:44:01 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_prints(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		return (6);
	}
	while (c[i] != '\0')
	{
		if (write(1, &c[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

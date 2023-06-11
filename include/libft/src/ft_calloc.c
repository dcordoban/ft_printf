/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:47:26 by david             #+#    #+#             */
/*   Updated: 2023/05/15 20:20:02 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*matriz;

	matriz = malloc (nmemb * size);
	if (matriz)
	{
		ft_memset(matriz, 0, nmemb * size);
		return (matriz);
	}
	return (0);
}

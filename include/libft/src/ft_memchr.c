/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:44:31 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/09 19:10:10 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	to_find;
	unsigned char	*ptr_to_src;
	size_t			i;

	ptr_to_src = (unsigned char *)s;
	i = 0;
	to_find = (unsigned char) c;
	while (i < n)
	{
		if (ptr_to_src[i] == to_find)
			return (&ptr_to_src[i]);
		i++;
	}
	return (0);
}

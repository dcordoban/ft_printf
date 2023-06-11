/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:04:08 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/18 18:53:11 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_to_dst;
	const unsigned char	*ptr_to_src;

	ptr_to_src = (unsigned char *) src;
	ptr_to_dst = (unsigned char *) dest;
	if (!ptr_to_dst && !ptr_to_src)
		return (ptr_to_dst);
	while (n-- > 0)
		*(ptr_to_dst++) = *(ptr_to_src++);
	return (dest);
}

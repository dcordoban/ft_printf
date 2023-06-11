/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:04:08 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/08 19:00:11 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_to_dst;
	unsigned char	*ptr_to_src;

	ptr_to_dst = (unsigned char *)dest;
	ptr_to_src = (unsigned char *)src;
	if (src < dest)
	{
		while (n)
		{
			ptr_to_dst[n - 1] = ptr_to_src[n - 1];
			n--;
		}
		dest = (void *)ptr_to_dst;
	}
	dest = ft_memcpy(ptr_to_dst, ptr_to_src, n);
	return (dest);
}

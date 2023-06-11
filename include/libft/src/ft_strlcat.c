/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:04:08 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/27 11:40:42 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	j = 0;
	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dst_len;
	if (size == 0)
		return (src_len);
	if (size < dst_len)
		return (src_len + size);
	else
	{
		while (src[j] && (dst_len + j) < size)
			dest[i++] = src[j++];
		if ((dst_len + j) == size && dst_len < size)
			dest[i - 1] = '\0';
		else
			dest[i] = '\0';
		return (src_len + dst_len);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:57:06 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/15 20:20:28 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	to_find;
	size_t			s_len;

	i = 0;
	to_find = (unsigned char) c;
	s_len = ft_strlen(s);
	while (i <= s_len)
	{
		if (s[i] == to_find)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

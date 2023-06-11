/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:54:29 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/09 18:43:16 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0' || haystack == needle)
		return ((char *) haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && haystack[i + j] != '\0'
			&& haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0' && haystack[i + j - 1] == needle[j - 1])
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}

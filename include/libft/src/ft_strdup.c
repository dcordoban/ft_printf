/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:41:38 by david             #+#    #+#             */
/*   Updated: 2023/05/18 18:43:43 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_copy;
	size_t	s_len;

	s_len = ft_strlen(s) + 1;
	s_copy = (char *)malloc(s_len * sizeof(char));
	if (s_copy)
	{
		ft_memcpy(s_copy, s, s_len);
		return (s_copy);
	}
	return (0);
}

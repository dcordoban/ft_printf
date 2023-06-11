/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:56:39 by david             #+#    #+#             */
/*   Updated: 2023/05/15 20:20:35 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	size_t	t_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	t_len = ft_strlen(s1) + ft_strlen(s2);
	j_str = (char *)malloc((t_len + 1) * sizeof(char));
	if (j_str)
	{
		if (t_len == 0)
			ft_memset(j_str, 0, 1);
		else
		{
			ft_memcpy(j_str, s1, s1_len);
			while (i < s2_len)
				j_str[s1_len++] = s2[i++];
			j_str[t_len] = '\0';
		}
		return (j_str);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 20:47:05 by david             #+#    #+#             */
/*   Updated: 2023/05/27 11:40:16 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_splits(char const *s, char c)
{
	int	is_split;
	int	counter;

	is_split = 0;
	counter = 0;
	while (*s)
	{
		if (*s != c && is_split == 0)
		{
			is_split = 1;
			counter++;
		}
		if (*s == c)
			is_split = 0;
		s++;
	}
	return (counter);
}

static void	ft_free_mem_all(char **container, int index)
{
	int	k;

	k = 0;
	while (k < index)
	{
		free(container[k]);
		k++;
	}
	free(container);
}

static char	**ft_fill_container(char const *s, char c, char **container, int k)
{
	int	i;
	int	split_start;

	i = 0;
	split_start = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		split_start = i;
		while (s[i] && s[i] != c)
			i++;
		if (split_start != i)
		{
			container[k] = ft_substr(s, split_start, (i - split_start));
			if (!(container[k++]))
			{
				ft_free_mem_all(container, k--);
				return (0);
			}
		}
	}
	container[k] = 0;
	return (container);
}

char	**ft_split(char const *s, char c)
{
	char	**container;
	int		k;

	k = 0;
	if (!s)
		return (0);
	container = (char **)malloc((count_splits(s, c) + 1) * sizeof(char *));
	if (!(container))
		return (0);
	return (ft_fill_container(s, c, container, k));
}

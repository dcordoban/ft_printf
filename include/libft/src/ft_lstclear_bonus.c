/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcordoba <dcordoba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:06:37 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/21 12:28:27 by dcordoba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*children;

	if (!lst)
		return ;
	while (*lst)
	{
		children = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = children;
	}
	*lst = NULL;
}

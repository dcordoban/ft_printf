/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 11:38:06 by dcordoba          #+#    #+#             */
/*   Updated: 2023/05/24 19:18:48 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*container;
	t_list	*res_list;
	t_list	*item;

	if (!lst || !f)
		return (0);
	container = 0;
	while (lst)
	{
		item = f(lst->content);
		res_list = ft_lstnew(item);
		if (!(res_list))
		{
			ft_lstclear(&container, del);
			free(item);
			return (0);
		}
		ft_lstadd_back(&container, res_list);
		lst = lst->next;
	}
	return (container);
}

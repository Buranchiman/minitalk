/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wvallee <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 11:44:55 by wvallee           #+#    #+#             */
/*   Updated: 2022/11/30 12:53:22 by wvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_fill(t_list *lst, void *(*f)(void *))
{
	t_list	*dest;

	if (f == NULL)
		dest = ft_lstnew(lst);
	else
		dest = ft_lstnew(f(lst->content));
	return (dest);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*init;
	t_list	*dest;

	if (lst == NULL)
		return (NULL);
	init = ft_fill(lst, f);
	dest = init;
	while (lst->next != NULL && dest != NULL)
	{
		dest->next = ft_fill(lst->next, f);
		if (dest->next == NULL)
		{
			ft_lstclear(&init, del);
			return (NULL);
		}
		lst = lst->next;
		dest = dest->next;
	}
	return (init);
}		

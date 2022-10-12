/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:14:01 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 15:48:04 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_mov;
	t_list	*new_elem;

	if (lst == NULL)
		return (NULL);
	if ((new = ft_lstnew((*f)(lst->content))) == NULL)
		return (NULL);
	new_mov = new;
	while ((lst = lst->next) != NULL)
	{
		if ((new_elem = ft_lstnew((*f)(lst->content))) == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		new_mov->next = new_elem;
		new_mov = new_mov->next;
	}
	return (new);
}

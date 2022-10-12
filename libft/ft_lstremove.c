/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 16:01:01 by lzins             #+#    #+#             */
/*   Updated: 2021/02/17 15:00:21 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstremove(t_list **alst, void *content, size_t content_size)
{
	t_list *lst;
	t_list *prev;

	prev = NULL;
	lst = *alst;
	while (lst)
	{
		if (!ft_memcmp(lst->content, content, content_size))
		{
			if (prev)
				prev->next = lst->next;
			else
				*alst = lst->next;
			lst->next = NULL;
			return (lst);
		}
		prev = lst;
		lst = lst->next;
	}
	return (NULL);
}

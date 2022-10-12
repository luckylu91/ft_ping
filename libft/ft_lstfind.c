/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:09:21 by lzins             #+#    #+#             */
/*   Updated: 2021/02/17 15:00:05 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *content, size_t content_size)
{
	while (lst)
	{
		if (!ft_memcmp(lst->content, content, content_size))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:33:29 by lzins             #+#    #+#             */
/*   Updated: 2021/03/25 14:35:12 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstskip(t_list *lst, int (*skip)(void *content))
{
	while (lst)
	{
		if (!(*skip)(lst->content))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
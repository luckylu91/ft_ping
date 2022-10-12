/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:31:58 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 16:33:42 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstindex(t_list *lst, void *content, size_t content_size)
{
	int i;

	i = 0;
	while (lst)
	{
		if (!ft_memcmp(lst->content, content, content_size))
			return (i);
		lst = lst->next;
		i++;
	}
	return (-1);
}

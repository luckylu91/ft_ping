/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstany.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:31:57 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 02:47:15 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstany(t_list *lst, int (*booleval)(void *content))
{
	while (lst)
	{
		if ((*booleval)(lst->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}

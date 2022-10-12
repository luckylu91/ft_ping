/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstany2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:45:59 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 02:47:34 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstany2(t_list *lst, void *ref, int (*booleval)(void *cont, void *ref))
{
	while (lst)
	{
		if ((*booleval)(lst->content, ref))
			return (1);
		lst = lst->next;
	}
	return (0);
}

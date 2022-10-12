/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:05:49 by lzins             #+#    #+#             */
/*   Updated: 2021/02/01 16:35:34 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_mov1;
	t_list	*lst_mov2;

	if (lst == NULL)
		return ;
	lst_mov1 = *lst;
	while (lst_mov1 != NULL)
	{
		lst_mov2 = lst_mov1->next;
		ft_lstdelone(lst_mov1, del);
		lst_mov1 = lst_mov2;
	}
	*lst = NULL;
}

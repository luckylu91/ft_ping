/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:12:04 by lzins             #+#    #+#             */
/*   Updated: 2021/03/28 12:39:41 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter_arg(t_list *lst, void *arg, void (*f)(void *cont, void *arg))
{
	while (lst != NULL)
	{
		(*f)(lst->content, arg);
		lst = lst->next;
	}
}

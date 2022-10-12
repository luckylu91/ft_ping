/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreviter_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:30:43 by lzins             #+#    #+#             */
/*   Updated: 2021/03/28 12:46:31 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreviter_arg(t_list *lst, void *arg,
	void (*f)(void *cont, void *arg))
{
	if (!lst)
		return ;
	ft_lstreviter_arg(lst->next, arg, f);
	(*f)(lst->content, arg);
}

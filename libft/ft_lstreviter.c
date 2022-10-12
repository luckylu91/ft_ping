/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreviter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:30:43 by lzins             #+#    #+#             */
/*   Updated: 2021/03/28 12:41:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreviter(t_list *lst, void (*f)(void *))
{
	if (!lst)
		return ;
	ft_lstreviter(lst->next, f);
	(*f)(lst->content);
}

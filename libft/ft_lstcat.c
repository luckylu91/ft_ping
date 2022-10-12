/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:07:08 by lzins             #+#    #+#             */
/*   Updated: 2021/02/17 14:59:59 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcat(t_list *lst1, t_list *lst2)
{
	if (!lst1)
		return (lst2);
	if (!lst2)
		return (lst1);
	ft_lstlast(lst1)->next = lst2;
	return (lst1);
}

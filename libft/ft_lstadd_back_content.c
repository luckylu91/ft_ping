/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:30:52 by lzins             #+#    #+#             */
/*   Updated: 2021/03/25 17:31:52 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd_back_content(t_list **alst, void *content)
{
	t_list *new_elem;

	if (!alst)
		return (0);
	new_elem = ft_lstnew(content);
	if (!new_elem)
		return (0);
	ft_lstadd_back(alst, new_elem);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststep.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:27:32 by lzins             #+#    #+#             */
/*   Updated: 2021/03/25 14:34:49 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lststep(t_list *lst, size_t n_steps)
{
	while (lst)
	{
		if (n_steps == 0)
			return (lst);
		lst = lst->next;
		n_steps--;
	}
	return (NULL);
}
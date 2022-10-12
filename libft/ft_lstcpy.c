/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:29:32 by lzins             #+#    #+#             */
/*   Updated: 2021/02/19 15:53:46 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcpy(t_list *src, t_list **adest, size_t content_size)
{
	void	*new_content;

	if (!adest)
		return (0);
	if (!src)
		return (1);
	*adest = NULL;
	new_content = NULL;
	if (!(new_content = malloc(content_size))
			|| !(*adest = ft_lstnew(new_content))
			|| !ft_lstcpy(src->next, &(*adest)->next, content_size))
	{
		free(new_content);
		free(*adest);
		return (0);
	}
	ft_memcpy(new_content, src->content, content_size);
	return (1);
}

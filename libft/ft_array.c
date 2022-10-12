/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:40:21 by lzins             #+#    #+#             */
/*   Updated: 2021/02/17 14:59:46 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	**free_error(void **grid, size_t size1)
{
	size_t i;

	i = 0;
	while (i < size1)
	{
		free(grid[i]);
		i++;
	}
	return (NULL);
}

void		**ft_array(size_t size1, size_t size2, size_t type_size)
{
	size_t	i;
	void	**grid;

	if (!(grid = ft_calloc(size1, sizeof(void*))))
		return (NULL);
	i = 0;
	while (i < size1)
	{
		if (!(grid[i] = ft_calloc(size2, type_size)))
			return (free_error(grid, size1));
		i++;
	}
	return (grid);
}

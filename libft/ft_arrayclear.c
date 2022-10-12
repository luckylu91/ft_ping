/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrayclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 14:25:01 by lzins             #+#    #+#             */
/*   Updated: 2021/02/10 15:45:44 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrayclear(void **array, size_t size)
{
	size_t i;

	i = 0;
	if (array)
	{
		while (i < size)
			free(array[i++]);
		free(array);
	}
}

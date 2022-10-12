/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 13:31:36 by lzins             #+#    #+#             */
/*   Updated: 2021/03/28 13:59:47 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intindex(const int *array, size_t n, int val)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (array[i] == val)
			return ((int)i);
		i++;
	}
	return (-1);
}

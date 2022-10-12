/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:47:09 by lzins             #+#    #+#             */
/*   Updated: 2020/11/23 08:17:04 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;
	unsigned char	c_uc;
	size_t			i;

	dst_uc = (unsigned char*)dst;
	src_uc = (unsigned char*)src;
	c_uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		dst_uc[i] = src_uc[i];
		if (src_uc[i] == c_uc)
			return (dst_uc + i + 1);
		i++;
	}
	return (NULL);
}

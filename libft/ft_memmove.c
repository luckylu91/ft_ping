/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:13:33 by lzins             #+#    #+#             */
/*   Updated: 2020/11/23 05:44:13 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	copy(unsigned char *dst, unsigned char *src, size_t n, int inc)
{
	size_t	start;
	size_t	stop;
	size_t	i;

	if (inc > 0)
	{
		start = 0;
		stop = n;
		inc = 1;
	}
	else
	{
		start = n - 1;
		stop = -1;
		inc = -1;
	}
	i = start;
	while (i != stop)
	{
		dst[i] = src[i];
		i += inc;
	}
}

void		*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;

	dst_uc = (unsigned char*)dst;
	src_uc = (unsigned char*)src;
	if (src_uc == dst_uc)
		return (dst);
	else if (dst_uc - src_uc < 0)
		copy(dst_uc, src_uc, n, 1);
	else
		copy(dst_uc, src_uc, n, -1);
	return (dst);
}

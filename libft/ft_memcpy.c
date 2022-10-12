/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:46:10 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 17:13:27 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_uc;
	unsigned char	*src_uc;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst_uc = (unsigned char*)dst;
	src_uc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		dst_uc[i] = src_uc[i];
		i++;
	}
	return (dst);
}

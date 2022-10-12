/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 06:53:18 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 17:01:33 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	char	*dst_end;

	if (src == NULL || dst == NULL)
		return (0);
	if (n > 0)
	{
		dst_end = ft_memccpy(dst, src, '\0', n - 1);
		if (dst_end == NULL)
			dst[n - 1] = '\0';
	}
	return (ft_strlen(src));
}

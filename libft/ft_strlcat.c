/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 07:05:08 by lzins             #+#    #+#             */
/*   Updated: 2020/11/23 07:13:00 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char	*dst_end;
	size_t	dst_len;

	dst_end = ft_strchr(dst, '\0');
	dst_len = (size_t)(dst_end - dst);
	if (dst_len >= n)
		return (n + ft_strlen(src));
	n -= dst_len;
	ft_strlcpy(dst_end, src, n);
	return (dst_len + ft_strlen(src));
}

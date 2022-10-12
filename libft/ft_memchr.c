/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:46:13 by lzins             #+#    #+#             */
/*   Updated: 2020/11/23 05:49:59 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_uc;
	unsigned char	c_uc;
	size_t			i;

	s_uc = (unsigned char*)s;
	c_uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (s_uc[i] == c_uc)
			return (s_uc + i);
		i++;
	}
	return (NULL);
}

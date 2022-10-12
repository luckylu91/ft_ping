/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 04:45:48 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 11:59:42 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_uchar;
	unsigned char	c_uchar;
	size_t			i;

	s_uchar = (unsigned char*)s;
	c_uchar = (unsigned char)c;
	i = 0;
	while (i < n)
		s_uchar[i++] = c_uchar;
	return (s);
}

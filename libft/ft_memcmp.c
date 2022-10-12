/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 05:50:24 by lzins             #+#    #+#             */
/*   Updated: 2020/11/23 05:55:55 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;
	size_t			i;

	s1_uc = (unsigned char*)s1;
	s2_uc = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (s1_uc[i] != s2_uc[i])
			return ((int)s1_uc[i] - (int)s2_uc[i]);
		i++;
	}
	return (0);
}

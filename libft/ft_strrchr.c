/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 06:19:53 by lzins             #+#    #+#             */
/*   Updated: 2020/11/23 08:31:34 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_prev;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	s_prev = NULL;
	while ((s = ft_strchr(s, c)) != NULL)
	{
		s_prev = s;
		s++;
	}
	return ((char*)s_prev);
}

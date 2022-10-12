/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:11:21 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 16:57:27 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;
	size_t			accum;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	len = 0;
	accum = 0;
	while (s1[start + accum + len] != '\0')
	{
		if (in_set(s1[start + accum + len], set))
		{
			start += (len == 0);
			accum += (len != 0);
		}
		else
		{
			len += accum + 1;
			accum = 0;
		}
	}
	return (ft_substr(s1, start, len));
}

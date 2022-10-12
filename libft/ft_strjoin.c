/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:28:28 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 16:56:29 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s12;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s12 = malloc(s1_len + s2_len + 1);
	if (s12 == NULL)
		return (NULL);
	s12[s1_len + s2_len] = '\0';
	ft_memcpy(s12, s1, s1_len);
	ft_memcpy(s12 + s1_len, s2, s2_len);
	return (s12);
}

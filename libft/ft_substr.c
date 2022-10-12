/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:17:26 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 16:55:57 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	new_len;
	char	*s_new;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		new_len = 0;
	else
		new_len = (s_len - start) < len ? s_len - start : len;
	s_new = malloc(new_len + 1);
	if (s_new == NULL)
		return (NULL);
	s_new[new_len] = '\0';
	if (start < s_len)
		ft_memcpy(s_new, s + start, new_len);
	return (s_new);
}

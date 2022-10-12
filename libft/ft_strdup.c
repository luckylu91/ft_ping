/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 09:47:46 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 10:11:55 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	s_len;

	s_len = ft_strlen(s);
	if ((s_dup = malloc(s_len + 1)) == NULL)
		return (NULL);
	return (ft_memcpy(s_dup, s, s_len + 1));
}

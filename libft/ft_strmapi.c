/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:03:13 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 16:58:26 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*s2;
	size_t			s_len;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	s2 = malloc(s_len + 1);
	if (s2 == NULL)
		return (NULL);
	s2[s_len] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	return (s2);
}

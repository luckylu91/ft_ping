/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 19:11:05 by lzins             #+#    #+#             */
/*   Updated: 2021/02/22 20:18:45 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strskip(char const *s, char *delim, int skip_sep, size_t *flen)
{
	int i;

	if (flen != NULL)
		*flen = 0;
	while (*s != '\0')
	{
		i = -1;
		while (delim[++i])
		{
			if (*s == delim[i])
				break ;
		}
		if ((skip_sep && !delim[i]) || (!skip_sep && *s == delim[i]))
			return ((char*)s);
		if (flen != NULL)
			(*flen)++;
		s++;
	}
	return ((char*)s);
}

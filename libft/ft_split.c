/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:16:45 by lzins             #+#    #+#             */
/*   Updated: 2021/02/17 15:00:29 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char const	*skip(char const *s, char *delim, int skip_sep,
	size_t *flen)
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
			return (s);
		if (flen != NULL)
			(*flen)++;
		s++;
	}
	return (s);
}

static char const	*skip_field(char const *s, char *delim, size_t *flen)
{
	s = skip(s, delim, 0, flen);
	s = skip(s, delim, 1, NULL);
	return (s);
}

static void			free_previous(char **array, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
}

static int			pass(char const *s, char *delim, char **s_array,
		size_t *n_fields)
{
	size_t		flen;
	size_t		i;
	char const	*s_prev;

	i = 0;
	while (*s != '\0')
	{
		s_prev = s;
		s = skip_field(s, delim, &flen);
		if (s_array != NULL)
		{
			s_array[i] = ft_substr(s_prev, 0, flen);
			if (s_array[i] == NULL)
			{
				free_previous(s_array, i);
				return (-1);
			}
		}
		i++;
	}
	if (n_fields != NULL)
		*n_fields = i;
	return (0);
}

char				**ft_split(char const *s, char *delim)
{
	size_t	n_fields;
	char	**s_array;

	if (s == NULL)
		return (NULL);
	s = skip(s, delim, 1, NULL);
	pass(s, delim, NULL, &n_fields);
	s_array = malloc((n_fields + 1) * sizeof(char*));
	if (s_array == NULL)
		return (NULL);
	if (pass(s, delim, s_array, NULL) == -1)
		return (NULL);
	s_array[n_fields] = NULL;
	return (s_array);
}

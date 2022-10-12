/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 15:49:04 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 15:50:47 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strindex(const char *s, int c)
{
	char *strchr_result;

	strchr_result = ft_strchr(s, c);
	if (!strchr_result)
		return (-1);
	return ((int)(strchr_result - s));
}

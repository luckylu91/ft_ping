/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_overflows.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:16:25 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 14:28:53 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

int			ft_atoi_overflows(const char *str)
{
	long	res;
	long	sgn;

	res = 0;
	sgn = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sgn = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if (sgn * res > (long)INT_MAX || sgn * res < (long)INT_MIN)
			return (1);
		str++;
	}
	return (0);
}

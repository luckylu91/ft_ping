/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 10:17:12 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 16:49:07 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	compute_digits(int n, int sgn, int *size, char *digits)
{
	int		i;

	if (n == 0)
	{
		*size = 1;
		digits[0] = '0';
		return ;
	}
	i = 0;
	while (n != 0)
	{
		digits[i] = '0' + sgn * (n % 10);
		n /= 10;
		i++;
	}
	*size = i;
}

static void	reverse_fill(char *s, char *digits, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		s[i] = digits[size - 1 - i];
		i++;
	}
}

char		*ft_itoa(int n)
{
	char	digits[10];
	int		sgn;
	int		size;
	char	*res;
	char	*res_mov;

	sgn = (n < 0) ? -1 : 1;
	compute_digits(n, sgn, &size, digits);
	res = malloc((size + 1 + (sgn == -1)) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res_mov = res;
	if (sgn == -1)
		*(res_mov++) = '-';
	reverse_fill(res_mov, digits, size);
	res_mov[size] = '\0';
	return (res);
}

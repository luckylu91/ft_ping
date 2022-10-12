/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:02:17 by lzins             #+#    #+#             */
/*   Updated: 2020/11/24 15:29:40 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n > 9 || n < -9)
	{
		ft_putnbr_fd(n / 10, fd);
		if (n > 0)
			ft_putnbr_fd(n % 10, fd);
		else
			ft_putnbr_fd(-(n % 10), fd);
	}
	else if (n >= 0)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd(-n + '0', fd);
	}
}

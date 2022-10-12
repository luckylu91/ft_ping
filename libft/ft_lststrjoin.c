/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:33:31 by lzins             #+#    #+#             */
/*   Updated: 2021/03/29 16:54:55 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int lststr_cat_len(t_list *lst)
{
	if (!lst)
		return (0);
	return (ft_strlen((char*)lst->content) + lststr_cat_len(lst->next));
}

static char *strcat_and_move(char *str, char *addition)
{
	while (*addition)
	{
		*str = *addition;
		str++;
		addition++;
	}
	return (str);
}

static void lststr_cat_sep(char *str, t_list *lst, char *sep)
{
	if (!lst)
		return ;
	str = strcat_and_move(str, (char*)lst->content);
	if (lst->next)
		str = strcat_and_move(str, sep);
	lststr_cat_sep(str, lst->next, sep);
}

char	*ft_lststrjoin(t_list *lst, char *sep, char *left, char *right)
{
	int		n;
	size_t	left_len;
	size_t	right_len;
	size_t	tot_len;
	char	*res;

	n = ft_lstsize(lst);
	left_len = ft_strlen(left);
	right_len = ft_strlen(right);
	tot_len = lststr_cat_len(lst) + left_len + right_len;
	if (n > 0)
		tot_len += (n - 1) * ft_strlen(sep);
	res = ft_calloc(tot_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (left)
		strcat_and_move(res, left);
	lststr_cat_sep(res + left_len, lst, sep);
	if (right)
		strcat_and_move(res + (tot_len - right_len), right);
	return (res);
}

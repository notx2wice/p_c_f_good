/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:56:59 by ukim              #+#    #+#             */
/*   Updated: 2020/08/16 18:17:53 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					get_len(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*str_cpy(char *str, int len)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

t_stock_str			*get_stock_str(t_stock_str *tab, char *str)
{
	tab->str = str;
	tab->size = get_len(str);
	tab->copy = str_cpy(str, tab->size);
	if (tab->copy == 0)
		return (0);
	return (tab);
}

void				memo_free_tab(t_stock_str *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i].copy);
		i++;
	}
	free(tab);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	t_stock_str	*tmp;
	int			i;

	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (result == 0)
		return (0);
	result[ac].str = 0;
	i = 0;
	while (i < ac)
	{
		tmp = get_stock_str(result + i, av[i]);
		if (tmp == 0)
		{
			memo_free_tab(result, i);
			return (0);
		}
		i++;
	}
	return (result);
}
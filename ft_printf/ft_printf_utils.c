/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:14:55 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 11:38:40 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*init_c_malloc(char c, int i)
{
	char				*str;

	str = malloc(i + 1);
	str[i] = 0;
	while (i--)
		str[i] = c;
	return (str);
}

char					*ft_right_strcat(char *str, char c, int width)
{
	int					i;
	char				*result;

	if (!c || !str)
		return (0);
	i = 0;
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(str) + width + 1))))
		return (0);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	while (width--)
		result[i++] = c;
	result[i] = '\0';
	return (result);
}

char					*ft_left_strcat(char *str, char c, int width)
{
	int					i;
	int					j;
	char				*result;

	if (!c || !str)
		return (0);
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(str) + width + 1))))
		return (0);
	i = 0;
	j = 0;
	while (width--)
		result[i++] = c;
	while (str[j])
		result[i++] = str[j++];
	result[i] = '\0';
	return (result);
}

int						ull_length(unsigned long long ull, int base)
{
	int					length;
	unsigned long long	tmp;

	tmp = ull;
	length = 0;
	while (tmp > 0)
	{
		tmp = tmp / base;
		length++;
	}
	return (length);
}

void					ft_putstr(char *str)
{
	int					len;

	if (!str)
		return ;
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 21:13:34 by ukim              #+#    #+#             */
/*   Updated: 2020/10/07 14:37:58 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char*)(ptr + i) = (unsigned char)value;
		i++;
	}
	return (ptr);
}
/*
** 바이트 단위로 변경한다. 값을 value의 값으로
** 이거랑 bzero는 널체크 안함 memcpy는 하던데 신기하넴
*/

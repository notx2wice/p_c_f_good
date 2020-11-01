/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:37:14 by ukim              #+#    #+#             */
/*   Updated: 2020/10/29 03:26:58 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		something_in_st(char **st_stored, int fd)// end == 0  fail == -1 normal == 1 잔여물이 남은 체로 들어왔고 잔여물중에 넥라는 없는 것이 확인 된 상태
{
	char 	*tmp;
	char 	*readed;
	int		ck;
	int		i;

	i = 0;
	if (!(readed = (char*)malloc(sizeof(char) * BUFF_SIZE +1)))
		return (-1);
	while (i <= BUFF_SIZE)
		readed[i++] = '\0';
	ck = read(fd, readed, BUFF_SIZE);
	if (ck == -1)
		return -1;
	tmp = ft_strjoin(readed, st_stored[fd]);
	free(st_stored[fd]);
	free(readed);
	st_stored[fd] = tmp;
	if (ck == 0)
		return (0);
	i = 0;
	while (i < ft_strlen(tmp))
		if (tmp[i] == '\n')
			return (2);
	return (1);
}

static	int		nothing_in_st(char **st_stored, int fd)// end == 0  fail == -1 normal == 1
{
	char	*tmp;
	int		i;
	int		ck;

	ck = 0;
	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while (i <= BUFF_SIZE)
		tmp[i++] = '\0';
	ck = read(fd, tmp, BUFF_SIZE);
	if (ck == -1)
		return (-1);
	st_stored[fd] = tmp;
	if (ck != BUFF_SIZE)
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char *st_stored[MAX_FILE];
	char		*tmp_buff;
	char		*tmp_address;
	size_t		i;

	i = 0;
	if (fd < 0 || fd > MAX_FILE || !line || !read(fd, st_stored[fd], 0)
		|| !(tmp_buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (!st_stored[fd])
	{
		i = nothing_in_st(st_stored, fd);
		if (i == 0)
		{
			*line = ft_strdup(&st_stored[fd][i]);
			free(st_stored[fd]);
			st_stored[fd] = NULL;
			return (0);
		}
		if (i == -1)
			return (-1);
	}
	i = 0;
	while (st_stored[fd][i] != '\n' || st_stored[fd][i]) // 전에 버퍼에 넥스트라인이 두개들어간 경우 eof인 경우는 이곳에 도달 못함.  read의 반환 값이 다를 경우 끝나는 것으로 하기 때문에
		i++;
	if (st_stored[fd][i] == '\n')
	{
		*line = ft_substr(st_stored[fd], 0, i - 1);
		tmp_address = ft_strdup(&st_stored[fd][i]);
		free(st_stored[fd]);
		st_stored[fd] = tmp_address;
		return (1);
	}
	i = 1;
	while (i == 1)
		i = something_in_st(st_stored, fd);
	return (1);
}
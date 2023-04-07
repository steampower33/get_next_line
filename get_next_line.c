/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/07 19:58:56 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_line(int fd, char *buf)
{
	char	readline[BUFFER_SIZE + 1];
	char	*res;
	char	*tmp;
	int		size;

	size = 1;
	res = buf;
	while (size)
	{
		size = read(fd, readline, BUFFER_SIZE);
		if (size == -1)
		{
			free(buf);
			return (NULL);
		}
		readline[size] = '\0';
		tmp = res;
		res = ft_strjoin(res, readline);
		free(tmp);
		if (!res)
			return (NULL);
		if (ft_strchr_idx(res, 10))
			break ;
	}
	return (res);
}

char	*ft_set_line(char **buf)
{
	char	*res;
	char	*tmp;
	int		idx;

	idx = 0;
	while ((*buf)[idx] && (*buf)[idx++] != '\n')
		;
	res = ft_strndup(*buf, idx);
	if (!res)
		return (NULL);
	tmp = *buf;
	*buf = ft_strndup(*buf + idx, ft_strlen(*buf) - idx);
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_get_line(fd, buf);
	if (!buf || !*buf)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	line = ft_set_line(&buf);
	return (line);
}

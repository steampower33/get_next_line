/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/07 21:53:21 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
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

t_list	*ft_get_list(int fd, t_list *fd_list)
{
	t_list	*fd_node;
	t_list	*fd_prev;

	if (!fd_list)
	{
		fd_list = (t_list *)malloc(sizeof(t_list));
		fd_list->fd = fd;
		return (fd_list);
	}
	fd_node = fd_list;
	while (1)
	{
		if (fd_node->fd == fd)
			return (fd_node);
		if (!fd_node->next)
		{
			fd_node->buf = NULL;
			fd_node->fd = fd;
			fd_node->next = NULL;
			return (fd_node);
		}
		else
		{
			fd_prev = fd_node;
			fd_node = fd_node->next;
			fd_node->prev = fd_prev;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_list	*fd_list;
	t_list			*fd_node;
	char			*line;
	t_list			*fd_prev;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_node = ft_get_list(fd, fd_list);
	if (!fd_node)
		return (NULL);
	fd_node->buf = ft_get_line(fd, fd_node->buf);
	if (!fd_node->buf || !*fd_node->buf)
	{
		fd_prev = fd_node->prev;
		fd_prev->next = fd_node->next;
		free(fd_node->buf);
		free(fd_node);
		return (NULL);
	}
	line = ft_set_line(&fd_node->buf);
	return (line);
}

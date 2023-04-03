/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/03 18:37:27 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(int fd, char *line, char *readline)
{
	int		size;
	char	*tmp;

	while (1)
	{
		size = read(fd, readline, BUFFER_SIZE);
		if (size == -1)
			return (NULL);
		if (!size)
			break ;
		readline[size] = '\0';
		if (!line)
			line = ft_strndup("", 1);
		tmp = line;
		line = ft_strjoin(line, readline);
		free(tmp);
		tmp = NULL;
		if (!line)
			return (NULL);
		if (ft_strchr_idx(line, 10))
			break ;
	}
	return (line);
}

char	*ft_set_line(char **line)
{
	int		idx;
	char	*tmp;
	char	*res;

	idx = 0;
	while ((*line)[idx] && (*line)[idx] != '\n')
		idx++;
	res = ft_strndup(*line, idx + 1);
	tmp = *line;
	*line = ft_strndup(*line + idx + 1, ft_strlen(*line) - idx);
	free(tmp);
	return (res);
}

char	*get_next_line(int fd)
{
	static char			*line = NULL;
	char				*readline;
	char				*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readline = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!readline)
		return (NULL);
	line = ft_get_line(fd, line, readline);
	free(readline);
	if (!line || *line == '\0')
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	res = ft_set_line(&line);
	return (res);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("./memo", O_RDONLY);
	while (1)
	{
		res = get_next_line(fd);
		if (!res)
			return (0);
		printf("%s", res);
	}
}

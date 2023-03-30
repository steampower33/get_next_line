/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/30 21:12:32 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	buff[1024][1024];
	int		idx;
	int		is_read;
	char	*res;
	int		res_idx;

	is_read = 1;
	idx = 0;
	if (0 < fd)
	{
		while (is_read > 0)
		{
			is_read = read(fd, &buff[idx], 1);
			if ((int)buff[idx] == 10)
				break ;
			idx++;
		}
	}
	else
		return (NULL);
	buff[idx + 1] = '\0';
	res = (char *)malloc(sizeof(char) * (idx + 1));
	res_idx = 0;
	while (buff[res_idx])
	{
		res[res_idx] = buff[res_idx];
		res_idx++;
	}
	res[res_idx] = '\0';
	return (res);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;

	fd = open("./memo", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}

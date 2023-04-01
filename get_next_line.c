/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/01 17:40:35 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buf;
	int			size;

	if (fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (size)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1 || size == 0)
			return (NULL);
		buf[size] = '\0';
		printf("%d %s\n", size, buf);
		printf("%ld\n", ft_strchr(buf, '\n') - buf);
		break ;
	}
}

int	main(void)
{
	int	fd;

	fd = open("./memo", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(1000));
}

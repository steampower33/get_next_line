/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/31 23:04:18 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			buf[BUFFER_SIZE + 1];
	int				size;
	char			*tmp;

	if (fd < 0)
		return (NULL);
	if (!lst)
		lst = ft_lstnew(fd);
	if (!lst)
		return (NULL);
	tmp = NULL;
	while (1)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		// printf("%d %s\n", size, buf);
		// printf("%ld\n", ft_strchr(buf, '\n') - buf);
		
	}
	return (lst->line);
}

int	main(void)
{
	int	fd;

	fd = open("./memo", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}

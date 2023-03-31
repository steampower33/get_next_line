/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:05:31 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/31 22:32:34 by seunlee2         ###   ########.fr       */
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
		tmp = ft_strndup(buf, BUFFER_SIZE + 1);
		if (ft_strchr(buf, '\n'))
		{
			if (!lst->line)
			{
				lst->line = ft_strndup(buf, ft_strchr(buf, '\n') - buf + 1);
				lst->idx = ft_strchr(buf, '\n') - buf + 2;
			}
			else
			{
				if (ft_strchr(lst->line, '\n'))
				{
					free(lst->line);
					lst->line = NULL;
				}
				lst->line = ft_strndup(buf, ft_strchr(buf, '\n') - buf + 1);
			}
			break ;
		}
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

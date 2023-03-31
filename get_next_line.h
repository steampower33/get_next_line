/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:06:40 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/31 22:16:38 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		fd;
	int		idx;
	char	*line;
	char	*next;
}	t_list;

char	*get_next_line(int fd);
t_list	*ft_lstnew(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strncat(char *dest, char *src, size_t nb);
char	*ft_strndup(const char *src, size_t size);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10000000000

#endif
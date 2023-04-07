/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:06:40 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/07 21:48:20 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char	*buf;
	int		fd;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
int		ft_strchr_idx(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *s, const char *s1, const char *s2, size_t s1_len);
char	*ft_strndup(const char *src, size_t size);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000000000

#endif
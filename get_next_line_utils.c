/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:32:05 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/31 23:02:10 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

t_list	*ft_lstnew(int fd)
{
	t_list	*l;

	l = (t_list *)malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l -> fd = fd;
	l -> line = NULL;
	l -> next = NULL;
	return (l);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	idx;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	idx = 0;
	while (idx < len + 1)
	{
		if (s[idx] == (char)c)
			return ((char *)&s[idx]);
		idx++;
	}
	return (0);
}

static char	*ft_strcat(char *s, const char *s1, const char *s2)
{
	size_t	idx;

	idx = 0;
	while (idx < ft_strlen(s1))
	{
		s[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (idx < ft_strlen(s2))
	{
		s[ft_strlen(s1) + idx] = s2[idx];
		idx++;
	}
	s[ft_strlen(s1) + idx] = '\0';
	return (s);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*s;

	if (!ft_strlen(s1) && !ft_strlen(s2))
		return ((char *)ft_calloc(sizeof(char), 1));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *) malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	return (ft_strcat(s, s1, s2));
}

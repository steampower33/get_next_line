/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:32:05 by seunlee2          #+#    #+#             */
/*   Updated: 2023/04/01 16:53:17 by seunlee2         ###   ########.fr       */
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

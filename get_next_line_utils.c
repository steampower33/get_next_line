/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:32:05 by seunlee2          #+#    #+#             */
/*   Updated: 2023/03/31 22:11:04 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t	src_len;
	size_t	dest_len;

	dest_len = 0;
	src_len = 0;
	while (dest[dest_len])
		dest_len++;
	while ((src[src_len] != '\0') && src_len < nb)
	{
		dest[dest_len] = src[src_len];
		dest_len++;
		src_len++;
	}
	dest[dest_len] = '\0';
	return (dest);
}

char	*ft_strndup(const char *src, size_t size)
{
	size_t	dest_len;
	char	*dest;

	dest = (char *)malloc((sizeof(char) * (size + 1)));
	if (dest == NULL)
		return (NULL);
	dest_len = 0;
	while (dest_len < size)
	{
		dest[dest_len] = src[dest_len];
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (dest);
}

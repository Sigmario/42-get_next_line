/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:44:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/24 18:48:19 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	s = (void *)src;
	d = (void *)dst;
	if (src == NULL && dst == NULL)
		return (NULL);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i[3];
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i[1] = ft_strlen(s1);
	i[2] = ft_strlen(s2);
	res = (char *)malloc(i[1] + i[2] + 1);
	if (res == NULL)
		return (free(s1), NULL);
	ft_memcpy(res, s1, i[1]);
	if (s1[0])
		free(s1);
	ft_memcpy(res + i[1], s2, i[2]);
	res[i[1] + i[2]] = 0;
	return (res);
}

char	*ft_strdup(char *s)
{
	char	*d;
	char	*t;

	if (s == NULL)
		return (NULL);
	d = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (d == NULL)
		return (NULL);
	t = d;
	while (*s)
		*t++ = *s++;
	*t = 0;
	return (d);
}

char	*ft_strchr(char *s, int c)
{
	while (s && *s != (char)c)
	{
		if (*s == 0)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 15:44:28 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/16 16:59:09 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i[3];
	char	*res;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i[1] = ft_strlen(s1);
	i[2] = ft_strlen(s2);
	res = (char *)malloc(i[1] + i[2] + 1);
	if (res == NULL)
		return (NULL);
	ft_memcpy(res, s1, i[1]);
	ft_memcpy(res + i[1], s2, i[2]);
	res[i[1] + i[2]] = 0;
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*d;
	char	*t;

	d = malloc(ft_strlen(s) + 1 * sizeof(char));
	if (d == NULL)
		return (NULL);
	t = d;
	while (*s)
		*t++ = *s++;
	*t = 0;
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s) - start;
	if (len > size)
		str = (char *)malloc(sizeof(char) * (size + 1));
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s))
		str[i++] = s[start++];
	str[i] = 0;
	return (str);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:57:53 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/24 19:41:58 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_lastline(char *str)
{
	int		i;
	int		len;
	char	*line;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	if (line[0] == '\0')
		return (NULL);
	return (line);
}

char	*ft_getbuf(char *str)
{
	int		i;
	int		len;
	int		rest;
	char	*buf;

	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	rest = len - i;
	buf = malloc(sizeof(char) * (rest + 1));
	if (buf == NULL)
		return (NULL);
	len = 0;
	while (str[i])
		buf[len++] = str[i++];
	buf[len] = '\0';
	if (buf[0] == '\0')
		free(buf);
	return (free(str), buf);
}

char	*get_next_line(int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	static char	*str;
	char		*line;

	if (fd <= -1 || fd >= 1024)
		return (NULL);
	size = 1;
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		if (!str)
			str = ft_strdup(buf);
		else
			str = ft_strjoin(str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	line = ft_lastline(str);
	str = ft_getbuf(str);
	return (line);
}

///*

int	main(void)
{
	int fd;
	int i;
	char *line;
	i = 1;
	fd = open("testline", O_RDONLY);
	while (i <= 30)
	{	
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("————————————————————\n");
		printf("  N°%d\t| %s", i, line);
		free(line);
		i++;
	}
	printf("————————————————————\n");
	close(fd);
	return (0);
}

//*/
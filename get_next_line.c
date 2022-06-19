/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:57:53 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/19 21:08:20 by julmuntz         ###   ########.fr       */
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
	char	*line;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		line[i] = str[i];
		i++;
		if (str[i] && str[i] == '\n')
		{
			line[i] = str[i];
			i++;
			break ;
		}
	}
	line[i] = '\0';
	return (line);
}

char	*ft_getbuf(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*buf;

	i = 0;
	j = 0;
	size = 0;
	while (str[j] != '\0')
		j++;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	size = i - j;
	if (size < 0)
		size *= -1;
	buf = malloc(sizeof(char) * (size + 1));
	j = 0;
	while (str[i])
		buf[j++] = str[i++];
	free(str);
	return (buf);
}

char	*get_next_line(int fd)
{
	int			size;
	char		buf[BUFFER_SIZE + 1];
	static char	*str;
	char		*line;

	size = 1;
	while (!ft_strchr(str, '\n') && size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
		str = ft_strjoin(str, buf);
	}
	line = ft_lastline(str);
	str = ft_getbuf(str);
	if (fd == -1)
		return (NULL);
	return (line);
}

/*

int	main(void)
{
	int fd;
	int i;
	char *line;
	i = 1;
	fd = open("testline", O_RDONLY);
	while (i)
	{
		line = get_next_line(fd);
		printf("————————————————————\n");
		printf("  N°%d\t| %s", i, line);
		free(line);
		i++;
	}
	printf("————————————————————\n");
	close(fd);
	return (0);
}

*/
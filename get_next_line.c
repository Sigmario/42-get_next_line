/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:57:53 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/16 17:05:00 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
int	endline(char *str)
{
	int	i = 0;
	if (str == NULL)
		return (0);
	while(str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char	*get_next_line(int fd)
{
	int		size;
	int		i;
	char	buf[BUFFER_SIZE];
	char	*str;
	char	*line;

	i = 0;
	size = 1;
	while (size > 0 && endline(buf) == 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		buf[size] = '\0';
	}
	ft_strjoin(buf, str);
	line = ft_substr(buf, fd, size);
	if (fd == -1)
	{
		printf("Error: \"open\" failed.\n");
		return (NULL);
	}
	return (line);
}

int	main()
{
	int	fd;
	fd = open("testline", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
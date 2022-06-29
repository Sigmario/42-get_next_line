/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:31:06 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/29 23:03:01 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_last_line(char *str)
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
		return (free(line), NULL);
	return (line);
}

char	*ft_get_buf(char *str)
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
	return (free(str), buf);
}

char	*get_next_line(int fd)
{
	int			size;
	char		*buf;
	static char	*str[FOPEN_MAX];
	char		*line;

	if (fd <= -1 || fd >= FOPEN_MAX)
		return (NULL);
	size = 1;
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (size > 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1 || (size == 0 && ft_strlen(str[fd]) == 0))
			return (free(buf), free(str[fd]), NULL);
		buf[size] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buf);
		else if (buf[0] != '\0')
			str[fd] = ft_strjoin(str[fd], buf);
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	line = ft_last_line(str[fd]);
	str[fd] = ft_get_buf(str[fd]);
	return (free(buf), line);
}

/*

int	main(void)
{
	int		fd[FOPEN_MAX];
	int		i;
	char	*line1;
	char	*line2;
	char	*line3;

	i = 1;
	fd[0] = open("testline-1", O_RDONLY);
	fd[1] = open("testline-2", O_RDONLY);
	fd[2] = open("testline-3", O_RDONLY);
	while (i)
	{	
		line1 = get_next_line(fd[0]);
		line2 = get_next_line(fd[1]);
		line3 = get_next_line(fd[2]);
		if (line1 == NULL && line2 == NULL && line3 == NULL)
			break ;
		printf("——————————————————————————————————\n");
		printf(" Line n°%d of...", i);
		printf("\tFD 1:\t%s", line1);
		printf("\t\tFD 2:\t%s", line2);
		printf("\t\tFD 3:\t%s", line3);
		free(line1);
		free(line2);
		free(line3);
		i++;
	}
	printf("——————————————————————————————————\n");
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	return (0);
}

*/
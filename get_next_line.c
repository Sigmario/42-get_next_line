/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:57:53 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/15 15:33:58 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

// char	*get_next_line(int fd)
// {
// 	return (NULL);
// }

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10

#endif

#define OK 0
#define KO 1

int	main()
{
	int	fd;
	char buf[BUFFER_SIZE];

	fd = open("get_next_line.c", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: \"open\" failed.\n");
		return (KO);
	}
	printf("ID: %d\n", fd);
	read(0, buf, BUFFER_SIZE - 1);
	buf[BUFFER_SIZE  - 1] = '\0';
	printf("%s\n", buf);


	close(fd);
	return (OK);
}
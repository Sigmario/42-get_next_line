/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julmuntz <julmuntz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:57:53 by julmuntz          #+#    #+#             */
/*   Updated: 2022/06/19 14:36:33 by julmuntz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_char_count(char *s, char c, int *index_chars)
{
	int	len;

	len = 0;
	while (s[*index_chars] && s[*index_chars] == c)
		(*index_chars)++;
	while (s[*index_chars + len] && s[*index_chars + len] != c)
		len++;
	return (len);
}

static int	ft_word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
		}
		else
		{
			while (s[i] && s[i] != c)
				i++;
			count++;
		}
	}
	return (count);
}

char	**ft_split(char *s, char const c)
{
	char	**tab;
	int		index_words;
	int		index_chars;
	int		nb_words;
	int		nb_chars;

	if (s == NULL)
		return (NULL);
	index_words = 0;
	index_chars = 0;
	nb_words = ft_word_count(s, c);
	tab = malloc(sizeof(char *) * (nb_words + 1));
	if (tab == NULL)
		return (NULL);
	while (index_words < nb_words)
	{
		nb_chars = ft_char_count(s, c, &index_chars);
		tab[index_words] = ft_substr(s, index_chars, nb_chars);
		index_chars += nb_chars;
		index_words++;
	}
	return (tab);
}

int	ft_lastline(char *str)
{
	static int	i = 0;
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
	char static	buf[BUFFER_SIZE];
	char	*str;

	size = 1;
	str = NULL;
	str = ft_substr(buf, fd, size);
	while (size > 0 && ft_lastline(buf) == 0)
	{
		ft_strjoin(buf, str); 
		size = read(fd, buf, BUFFER_SIZE); //buf = Alpha\nBrav // buf = o\nCharlie\n // buf = Delta\nEcho
		buf[size] = '\0';
	}
	if (fd == -1)
	{
		printf("Error: \"open\" failed.\n");
		return (NULL);
	}
	str = *ft_split(buf, '\n');
	return (ft_strdup(str));
}

int	main()
{
	int	fd;
	int	i;
	char *line;
	i = 1;
	fd = open("testline", O_RDONLY);
	while(i <= 2)
	{
		line = get_next_line(fd);
		printf("- LINE %d:\n%s\n\n", i ,line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:14:41 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/25 14:14:44 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*return_next_line(char **line)
{
	char	*text;
	char	*t;
	size_t	len;

	len = 0;
	text = NULL;
	while ((*line)[len] != '\n' && (*line)[len])
		len++;
	if ((*line)[len] == '\n')
	{
		text = ft_substr(*line, 0, len + 1);
		t = ft_strdup(*line + len + 1);
		free(*line);
		*line = t;
		if (!**line)
		{
			free(*line);
			*line = NULL;
		}
		return (text);
	}
	text = ft_strdup(*line);
	free(*line);
	*line = NULL;
	return (text);
}

static char	*check_and_return(char **line, ssize_t n)
{
	if (n < 0)
		return (NULL);
	if (!n && (!line || !*line))
		return (NULL);
	return (return_next_line(line));
}

char	*get_next_line(int fd)
{
	char		*t;
	char		*buff;
	static char	*line;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	n = read(fd, buff, BUFFER_SIZE);
	while (n > 0)
	{
		buff[n] = '\0';
		if (!line)
			line = ft_strdup("");
		t = ft_strjoin(line, buff);
		free(line);
		line = t;
		if (ft_strchr(buff, '\n'))
			break ;
		n = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (check_and_return(&line, n));
}

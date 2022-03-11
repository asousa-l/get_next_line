/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:18:43 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/25 14:18:56 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*return_next_line(char **s)
{
	char	*out;
	char	*tmp;
	size_t	len;

	len = 0;
	out = NULL;
	while ((*s)[len] != '\n' && (*s)[len])
		len++;
	if ((*s)[len] == '\n')
	{
		out = ft_substr(*s, 0, len + 1);
		tmp = ft_strdup(*s + len + 1);
		free(*s);
		*s = tmp;
		if (!**s)
		{
			free(*s);
			*s = NULL;
		}
		return (out);
	}
	out = ft_strdup(*s);
	free(*s);
	*s = NULL;
	return (out);
}

static char	*check_and_return(char **s, ssize_t n, int fd)
{
	if (n < 0)
		return (NULL);
	if (!n && (!s[fd] || !*s[fd]))
		return (NULL);
	return (return_next_line(&s[fd]));
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buff;
	static char	*s[FD_SIZE];
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
		if (!s[fd])
			s[fd] = ft_strdup("");
		tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
		n = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (check_and_return(s, n, fd));
}

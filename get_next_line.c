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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:14:24 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/25 14:14:24 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char	*check_and_return(char **s, ssize_t n)
{
	if (n < 0)
		return (NULL);
	if (!n && (!s || !*s))
		return (NULL);
	return (return_next_line(s));
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*buff;
	static char	*s;
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
		if (!s)
			s = ft_strdup("");
		tmp = ft_strjoin(s, buff);
		free(s);
		s = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
		n = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (check_and_return(&s, n));
}

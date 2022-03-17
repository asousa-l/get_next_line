/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:17:59 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/25 14:18:16 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *line)
{
	size_t	cnt;

	cnt = 0;
	while (line[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strchr(const char *line, int c)
{
	if (c == '\0')
		return ((char *)&line[ft_strlen(line)]);
	while (*line)
	{
		if (*line == (char)c)
			return ((char *)line);
		line++;
	}
	return (NULL);
}

char	*ft_strdup(const char *line)
{
	char	*a;
	char	*b;
	size_t	len;

	len = ft_strlen(line);
	a = malloc(len + 1);
	if (!a)
		return (NULL);
	b = a;
	while (*line)
		*a++ = *line++;
	*a = '\0';
	return (b);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*b;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	b = join;
	while (*s1)
		*join++ = *s1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (b);
}

char	*ft_substr(char const *line, unsigned int start, size_t len)
{
	size_t	join_len;
	char	*b;
	char	*join;

	if (!line)
		return (NULL);
	if (ft_strlen(line) < start)
		return (ft_strdup(""));
	join_len = ft_strlen(line + start);
	if (join_len < len)
		len = join_len;
	join = malloc(len + 1);
	if (!join)
		return (NULL);
	b = join;
	line += start;
	while (*line && len--)
		*join++ = *line++;
	*join = '\0';
	return (b);
}

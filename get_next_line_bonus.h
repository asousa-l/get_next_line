/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asousa-l <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:19:01 by asousa-l          #+#    #+#             */
/*   Updated: 2022/02/25 14:19:17 by asousa-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *line);
char	*ft_strchr(const char *line, int c);
char	*ft_strdup(const char *line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *line, unsigned int start, size_t len);

#endif

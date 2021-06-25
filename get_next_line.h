/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuliokaaz <tuliokaaz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:56:03 by tuliokaaz         #+#    #+#             */
/*   Updated: 2021/06/25 14:42:45 by tuliokaaz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define GET_NEXT_LINE_H
# define MAX_FD 1024 + 1

# define _ERROR -1
# define _EOF 0
# define _A_LINE 1

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char const *str);
char	*ft_strchr(char const *str, int c);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strdup(char const *str);
void	*ft_memmove(void *dst, const void *src, size_t n);
int		get_next_line(int fd, char **line);

#endif

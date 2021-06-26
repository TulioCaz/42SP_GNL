/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuliokaaz <tuliokaaz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 17:21:45 by tuliokaaz         #+#    #+#             */
/*   Updated: 2021/06/26 17:22:51 by tuliokaaz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1025

# define _ERROR -1
# define _EOF 0
# define _A_LINE 1

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(char const *str);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strjoin(char const *str1, char const *str2);
int		get_next_line(int fd, char **line);

#endif

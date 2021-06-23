/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuliokaaz <tuliokaaz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:56:03 by tuliokaaz         #+#    #+#             */
/*   Updated: 2021/06/23 18:50:29 by tuliokaaz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(char const *str, int c);
size_t	ft_strlen(char const *str);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strdup(char const *str);

#endif

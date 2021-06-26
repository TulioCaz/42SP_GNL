/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuliokaaz <tuliokaaz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:55:43 by tuliokaaz         #+#    #+#             */
/*   Updated: 2021/06/25 20:12:56 by tuliokaaz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst <= src)
		return (ft_memcpy(dst, src, n));
	d += n;
	s += n;
	while (n--)
		*--d = *--s;
	return (dst);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*buff;
	size_t	s1_len;
	size_t	s2_len;

	if (!str1 && !str2)
		return (NULL);
	if (!str2)
		return ((char *)str1);
	s1_len = ft_strlen(str1);
	s2_len = ft_strlen(str2);
	buff = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!buff)
		return (NULL);
	ft_memmove(buff, str1, s1_len);
	ft_memmove(buff + s1_len, str2, s2_len);
	buff[s1_len + s2_len] = '\0';
	free((char *)str1);
	return (buff);
}

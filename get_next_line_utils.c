/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuliokaaz <tuliokaaz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:55:43 by tuliokaaz         #+#    #+#             */
/*   Updated: 2021/06/23 18:22:50 by tuliokaaz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char const *str, int c)
{
	char	*s;

	s = (char *) str;
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	if (*s == '\0' && c == '\0')
		return (s);
	return (NULL);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	if (!str1)
		return (NULL);
	if (!str2)
		return ((char *)str1);
	s1_len = ft_strlen(str1);
	s2_len = ft_strlen(str2);
	str = ft_calloc(sizeof(char), (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, str1, s1_len + 1);
	ft_strlcat(str + s1_len, str2, s2_len + 1);
	return (str);
}

char	*ft_strdup(char *str)
{
	size_t	len;
	void	*new;

	len = ft_strlen(str) + 1;
	new = ft_calloc(sizeof(char), len);
	if (!new)
		return (NULL);
	return (ft_memcpy(new, str, len));
}

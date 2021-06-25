/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuliokaaz <tuliokaaz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:49:38 by tuliokaaz         #+#    #+#             */
/*   Updated: 2021/06/25 15:57:35 by tuliokaaz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	find_end_line(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(buff = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*get_save(char *save)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if(!save[i])
	{
		free(save);
		return (NULL);
	}
	if (!(tmp = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (NULL);
	i++;
	while (save[i])
		tmp[j++] = save[i++];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved;
	char		*tmp;
	int			bytes_read;

	bytes_read = 1;
	if (!line || (fd < 0 || fd > MAX_FD) || BUFFER_SIZE <= 0)
		return (_ERROR);
	if (!(tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (_ERROR);
	while (!find_end_line(saved) && bytes_read != 0)
	{
		if ((bytes_read = read(fd, tmp, BUFFER_SIZE)) == -1)
		{
			free(tmp);
			return (_ERROR);
		}
		tmp[bytes_read] = '\0';
		saved = ft_strjoin(saved, tmp);
	}
	free(tmp);
	*line = get_line(saved);
	saved = get_save(saved);
	if (bytes_read == 0)
		return (_EOF);
	return (_A_LINE);
}

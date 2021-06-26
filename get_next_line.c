/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuliokaaz <tuliokaaz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:49:38 by tuliokaaz         #+#    #+#             */
/*   Updated: 2021/06/25 20:32:55 by tuliokaaz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	find_end_line(char *str)
{
	int	i;

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

static char	*get_line(char *str)
{
	int		i;
	char	*buff;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * (i + 1));
	if (!buff)
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

static char	*get_save(char *save)
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
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1));
	if (!tmp)
		return (NULL);
	i++;
	while (save[i])
		tmp[j++] = save[i++];
	tmp[j] = '\0';
	free(save);
	return (tmp);
}

int	is_valid(int fd, char **line, char *buffer)
{
	if (!line || BUFFER_SIZE <= 0)
		return (_ERROR);
	else if (fd < 0 || fd > MAX_FD)
	{
		free(buffer);
		return (_ERROR);
	}
	else if (BUFFER_SIZE <= 0)
		return (_ERROR);
	else if (!buffer)
		return (_ERROR);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved;
	char		*buffer;
	int			bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (is_valid(fd, line, buffer) == -1)
		return (_ERROR);
	bytes_read = 1;
	while (!find_end_line(saved) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (_ERROR);
		}
		buffer[bytes_read] = '\0';
		saved = ft_strjoin(saved, buffer);
	}
	free(buffer);
	*line = get_line(saved);
	saved = get_save(saved);
	if (bytes_read == 0)
		return (_EOF);
	return (_A_LINE);
}

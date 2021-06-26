/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuliokaaz <tuliokaaz@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 16:49:38 by tuliokaaz         #+#    #+#             */
/*   Updated: 2021/06/26 15:13:59 by tuliokaaz        ###   ########.fr       */
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

static char	*get_save(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	tmp = malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	if (!tmp)
		return (NULL);
	i++;
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free(str);
	return (tmp);
}

int	is_valid(int fd, char **line, char *buff)
{
	if (!line || BUFFER_SIZE <= 0)
	{
		free(buff);
		return (_ERROR);
	}
	else if (fd < 0 || fd > MAX_FD)
	{
		free(buff);
		return (_ERROR);
	}
	else if (BUFFER_SIZE <= 0)
	{
		free(buff);
		return (_ERROR);
	}
	else if (!buff)
	{
		free(buff);
		return (_ERROR);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*saved[MAX_FD];
	char		*buffer;
	int			bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (is_valid(fd, line, buffer) == -1)
		return (_ERROR);
	bytes_read = 1;
	while (!find_end_line(saved[fd]) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (_ERROR);
		}
		buffer[bytes_read] = '\0';
		saved[fd] = ft_strjoin(saved[fd], buffer);
	}
	free(buffer);
	*line = get_line(saved[fd]);
	saved[fd] = get_save(saved[fd]);
	if (bytes_read == 0)
		return (_EOF);
	return (_A_LINE);
}

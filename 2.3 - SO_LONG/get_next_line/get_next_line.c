/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:07 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_error(char *buffer, char *line)
{
	size_t	index;

	index = 0;
	while (index < BUFFER_SIZE)
	{
		buffer[index] = NULL_CHAR;
		index++;
	}
	free(line);
	return (NULL);
}

static void	ft_clear(char *buffer, int size, int shift)
{
	int	index;

	index = 0;
	while (index < size - shift)
	{
		buffer[index] = buffer[index + shift];
		index++;
	}
	if (index < BUFFER_SIZE + 1)
		buffer[index] = NULL_CHAR;
}

static char	*ft_fill_line(char *buffer, int size, char *line)
{
	char	*temp;

	temp = ft_strndup(buffer, ft_find_nl(buffer, size) + 1);
	if (temp == NULL)
		return (ft_free_error(buffer, line));
	line = ft_gnl_strjoin(line, temp, size);
	free(temp);
	if (line == NULL)
		return (ft_free_error(buffer, line));
	return (line);
}

char	*get_next_line(int fd)
{
	int			size;
	char		*line;
	static char	buffer[FD_MAX][BUFFER_SIZE];

	size = sizeof(buffer[fd]);
	line = NULL;
	if (fd < 0 || fd > FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (size > 0 && ft_find_nl(buffer[fd], size) == NO_NL)
	{
		line = ft_gnl_strjoin(line, buffer[fd], size);
		if (line == NULL)
			return (ft_free_error(buffer[fd], line));
		size = read(fd, buffer[fd], BUFFER_SIZE);
		if (size < 0)
			return (ft_free_error(buffer[fd], line));
		if (size < BUFFER_SIZE)
			buffer[fd][size] = NULL_CHAR;
	}
	if (ft_find_nl(buffer[fd], size) >= 0)
		line = ft_fill_line(buffer[fd], size, line);
	ft_clear(buffer[fd], size, ft_find_nl(buffer[fd], size) + 1);
	if (ft_check_error(line, buffer[fd], size) == TRUE)
		return (ft_free_error(buffer[fd], line));
	return (line);
}

char	*ft_strndup(const char *buffer, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	while (i < n)
	{
		dup[i] = buffer[i];
		i++;
	}
	dup[n] = '\0';
	return (dup);
}

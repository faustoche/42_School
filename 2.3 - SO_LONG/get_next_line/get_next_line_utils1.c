/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:01 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strjoin(char *s1, char const *s2, int size)
{
	char	*str;

	if ((int)ft_strlen(s2) < size)
		size = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + size + 1));
	if (str == NULL)
		return (free(s1), NULL);
	str[0] = NULL_CHAR;
	ft_strlcat(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, ft_strlen(s1) + size + 1);
	free(s1);
	return (str);
}

int	ft_find_nl(const char *buffer, int size)
{
	int	index;

	index = 0;
	while (index < size && buffer[index] != NULL_CHAR)
	{
		if (buffer[index] == NL_CHAR)
			return (index);
		index++;
	}
	return (NO_NL);
}

bool	ft_check_error(char *line, char *buffer, size_t size)
{
	return (line == NULL || (line[0] == NULL_CHAR
			&& ft_find_nl(buffer, size) == NO_NL));
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}	
	if (*s == (char)c)
		return ((char *)s);
	else
		return (0);
}

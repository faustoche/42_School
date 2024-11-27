/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:53:27 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Used in split. */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cpy;
	size_t	len_s;

	if (!s)
	{
		return (NULL);
	}
	len_s = ft_strlen(s);
	if (start < len_s)
	{
		if (len_s - start < len)
			len = len_s - start;
		cpy = (char *)malloc((len + 1) * sizeof(char));
		if (!cpy)
			return (NULL);
		ft_strlcpy(cpy, s + start, len + 1);
	}
	else
		return (ft_strdup(""));
	return (cpy);
}

/* Duplicates the string. */

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	dest = malloc(sizeof(*dest) * (len + 1));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* Find the length of the string. */

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/* Copies the string. */

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	if (n == 0)
	{
		return (i);
	}
	while ((n > 1) && (*src != '\0'))
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	*dst = '\0';
	return (i);
}

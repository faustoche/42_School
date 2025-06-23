/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcrocq <fcrocq@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 19:57:38 by asaulnie          #+#    #+#             */
/*   Updated: 2025/06/22 15:51:52 by fcrocq           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*extract_filename(char *filename)
{
	int	i;
	int	last_slash;

	i = 0;
	last_slash = -1;
	while (filename[i])
	{
		if (filename[i] == '/')
			last_slash = i;
		i++;
	}
	if (last_slash != -1)
		return (ft_strdup(filename + last_slash + 1));
	else
		return (ft_strdup(filename));
}

static int	has_trailing_cub(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

static int	has_extra_dot_cub(char *path)
{
	size_t	i;
	size_t	len;
	char	*filename;

	i = 0;
	filename = extract_filename(path);
	if (!filename)
		return (1);
	len = ft_strlen(filename);
	if (len == 4 && ft_strcmp(filename, ".cub") == 0)
	{
		(printf("Error\nWrong filename\n"), free(filename));
		return (1);
	}
	if (len < 4 || ft_strcmp(filename + len - 4, ".cub") != 0)
		return (printf("Error\nMissing .cub extension\n"), free(filename), 1);
	while (i + 3 < len - 4)
	{
		if (filename[i] == '.' && filename[i + 1] == 'c'
			&& filename[i + 2] == 'u' && filename[i + 3] == 'b')
			return (printf("Error\nWrong filename\n"), free(filename), 1);
		i++;
	}
	free(filename);
	return (0);
}

int	check_extension(char *filename)
{
	if (!filename)
	{
		printf("Error\nFilename is null\n");
		return (-1);
	}
	if (has_extra_dot_cub(filename))
		return (-1);
	if (!has_trailing_cub(filename))
	{
		printf("Error\nFile extension must be exactly '.cub'\n");
		return (-1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:54:11 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../ft_printf/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <string.h>

/* -------------------------------------------------------------------------- */
/*                                   MACROS                                   */
/* -------------------------------------------------------------------------- */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE    10
# endif

# if BUFFER_SIZE > 999999
#  undef BUFFER_SIZE
#  define BUFFER_SIZE    999999
# endif

# define FD_MAX            1024
# define NL_CHAR            '\n'
# define TRUE            1
# define NULL_CHAR        '\0'
# define NO_NL            -1
# define ERROR            -1

char			*ft_gnl_strjoin(char *s1, char const *s2, int size);
int				ft_find_nl(const char *buffer, int size);
bool			ft_check_error(char *line, char *buffer, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*get_next_line(int fd);
size_t			ft_strlen(const char *s);
char			*ft_strndup(const char *buffer, size_t n);

#endif
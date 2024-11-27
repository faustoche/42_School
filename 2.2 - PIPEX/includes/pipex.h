/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:53:05 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stddef.h>
# include <sys/wait.h>
# include <stdarg.h>
# include "../ft_printf/ft_printf.h"

/* Errors */

void	error_handling(const char *message);
void	free_split(char **args);

/* Pipes */

int		open_file(const char *filename, int flags, int permissions);
void	create_pipe(int pfile[2]);
void	close_and_wait(int pfile[2], int proc1, int proc2);
void	close_pipes(int **pfile);

/* Process */

int		first_process(int file1, int pfile[2], char *cmd);
int		second_process(int file2, int pfile[2], char *cmd);
void	execute_command(char *command);
char	**split_command(char *command);

/* Split. */

char	ft_count_word(const char *str, char c);
void	free_str(size_t i, char **str);
size_t	word_size(char const *s, char c);
char	**other_split(char const *s, char c, char **str, size_t words_count);
char	**ft_split(char const *s, char c);

/* Utils */

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(char *src);
int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

#endif

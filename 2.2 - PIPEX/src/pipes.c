/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:53:18 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
** Open the file with flags and permissions
** If we can't open the file, print error and exit
*/

int	open_file(const char *filename, int flags, int permissions)
{
	int	file;

	file = open(filename, flags, permissions);
	if (file < 0)
	{
		ft_printf("No such file or directory: %s\n", filename);
		exit (EXIT_FAILURE);
	}
	return (file);
}

/* 
** Create the pipe
** If we can't create the pipe, print error and exit
*/

void	create_pipe(int pfile[2])
{
	if (pipe(pfile) == -1)
	{
		ft_printf("Can't create the pipe\n");
		exit (EXIT_FAILURE);
	}
}

/* 
** Close the files descriptor
** Wait for the child processes to end 
*/

void	close_and_wait(int pfile[2], int proc1, int proc2)
{
	close(pfile[0]);
	close(pfile[1]);
	waitpid(proc1, NULL, 0);
	waitpid(proc2, NULL, 0);
}

/* 
** Close the pipes to avoid leaks
*/

void	close_pipes(int **pfile)
{
	close(*pfile[0]);
	close(*pfile[1]);
}

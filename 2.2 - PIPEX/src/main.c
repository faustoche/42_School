/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:53:13 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* 
** Main function
** Check if the number of arguments
** Open the 1st file in read-only mode
** Open the 2nd file in read and write mode
** Create a pipe and the parent/child process
** Call close and wait
*/

int	main(int ac, char **av)
{
	int	file1;
	int	file2;
	int	pfile[2];
	int	proc1;
	int	proc2;

	if (ac != 5)
	{
		ft_printf("Wrong number of arguments\n");
		exit(EXIT_FAILURE);
	}
	file1 = open_file(av[1], O_RDONLY, 0);
	file2 = open_file(av[4], O_RDWR | O_TRUNC, 0644);
	create_pipe(pfile);
	proc1 = first_process(file1, pfile, av[2]);
	proc2 = second_process(file2, pfile, av[3]);
	close(file1);
	close(file2);
	close_and_wait(pfile, proc1, proc2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faustoche <faustoche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:55:47 by faustoche         #+#    #+#             */
/*   Updated: 2024/11/27 18:53:21 by faustoche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Create the first process with fork()
** Child process : standard entry goes to file 1, standard exit goes to pfile
** Close unused file descriptor
** Execute the first command
** Parent process : return PID of child process created for the first command
*/

int	first_process(int file1, int pfile[2], char *cmd)
{
	int	proc1;

	proc1 = fork();
	if (proc1 == 0)
	{
		dup2(file1, STDIN_FILENO);
		dup2(pfile[1], STDOUT_FILENO);
		close(file1);
		close(pfile[0]);
		close(pfile[1]);
		execute_command(cmd);
	}
	else if (proc1 < 0)
	{
		ft_printf("Error : can't create the process\n");
		exit (EXIT_FAILURE);
	}
	return (proc1);
}

/*
** Create the first process with fork()
** Child process : standard entry goes to pfile, standard exit goes to file2
** Close unused file descriptor
** Execute the second command
** Parent process : return PID of child process created for the second command
*/

int	second_process(int file2, int pfile[2], char *cmd)
{
	int	proc2;

	proc2 = fork();
	if (proc2 == 0)
	{
		dup2(pfile[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		close(file2);
		close(pfile[1]);
		close(pfile[0]);
		execute_command(cmd);
	}
	else if (proc2 < 0)
	{
		ft_printf("Can't create the process\n");
		exit(EXIT_FAILURE);
	}
	return (proc2);
}

/* 
** Divide the commands into arguments with split
** Execute the command using  execvp
** If fails, print error and free memory
*/

void	execute_command(char *command)
{
	char	**args;

	if (command == NULL || command[0] == '\0')
		error_handling("Command not found");
	args = split_command(command);
	if (!args)
		error_handling("Command not found");
	if (execvp(args[0], args) == -1)
	{
		free_split(args);
		error_handling("Command not found");
		exit(EXIT_FAILURE);
	}
	free_split(args);
}

/* 
** Split the command to have 2 separate ones
*/

char	**split_command(char *command)
{
	char	**args;

	if (command == NULL || command[0] == '\0')
		return (NULL);
	args = ft_split(command, ' ');
	if (!args || !args[0])
	{
		free_split(args);
		return (NULL);
	}
	return (args);
}

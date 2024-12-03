/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:31:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/12/02 14:37:08 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	init_valgrind(t_args *args)
{
	args->cmd1 = NULL;
	args->cmd2 = NULL;
	args->cmd1_path = NULL;
	args->cmd2_path = NULL;
	args->command1 = NULL;
	args->command2 = NULL;
	args->file1 = NULL;
	args->file2 = NULL;
	args->fd1 = 0;
	args->fd2 = 0;
}

void	init_args(t_args *args, char **argv)
{
	int	x;

	x = 1;
	init_valgrind(args);
	args->file1 = argv[x++];
	args->command1 = ft_split(argv[x++], ' ');
	if (!args->command1)
		manage_errors(args, "ft_split");
	args->cmd1 = ft_strjoin("/", args->command1[0]);
	if (!args->cmd1)
		manage_errors(args, "ft_strjoin");
	args->command2 = ft_split(argv[x++], ' ');
	if (!args->command2)
		manage_errors(args, "ft_split");
	args->cmd2 = ft_strjoin("/", args->command2[0]);
	if (!args->cmd2)
		manage_errors(args, "ft_strjoin");
	args->file2 = argv[x++];
}

void	open_infile(t_args *args)
{
	args->fd1 = open(args->file1, O_RDONLY);
	if (args->fd1 < 0)
		manage_errors(args, "open");
}

void	open_outfile(t_args *args)
{
	if (access(args->file2, F_OK) != 0)
	{
		args->fd2 = open(args->file2, O_CREAT | O_WRONLY | O_TRUNC, 0777);
		if (args->fd2 < 0)
			manage_errors(args, "open");
	}
	else
	{
		args->fd2 = open(args->file2, O_WRONLY | O_TRUNC);
		if (args->fd2 < 0)
			manage_errors(args, "open");
	}
}

void	child_process_cmd(t_args *args, int pipefd[2], char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		manage_errors(args, "fork");
	if (pid == 0)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			manage_errors(args, "dup2");
		close(pipefd[0]);
		if (execve(args->cmd1_path, args->command1, envp) == -1)
			manage_errors(args, "execve");
	}
	else
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			manage_errors(args, "dup2");
		waitpid(pid, NULL, 0);
	}
}

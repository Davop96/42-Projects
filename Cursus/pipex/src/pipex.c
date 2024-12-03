/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:33:56 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/12/02 15:31:21 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_pipex(t_args	*args, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		manage_errors(args, "pipe");
	if (dup2(args->fd1, STDIN_FILENO) == -1)
		manage_errors(args, "dup2");
	child_process_cmd(args, pipefd, envp);
	if (dup2(args->fd2, STDOUT_FILENO) == -1)
		manage_errors(args, "dup2");
	pid = fork();
	if (pid == -1)
		manage_errors(args, "fork");
	if (pid == 0)
	{
		if (execve(args->cmd2_path, args->command2, envp) == -1)
			manage_errors(args, "execve");
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_args	*args;

	if (envp[0] == NULL)
	{
		ft_printf("Error: No environment variables\n");
		exit(EXIT_FAILURE);
	}
	if (ac == 5)
	{
		args = malloc(sizeof(t_args));
		if (!args)
			manage_errors(args, "malloc");
		init_args(args, av);
		*args = check_args(args, envp);
		open_infile(args);
		open_outfile(args);
		ft_pipex(args, envp);
		free_args(args);
	}
	else
	{
		ft_printf("Error: Incorrect number of arguments\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

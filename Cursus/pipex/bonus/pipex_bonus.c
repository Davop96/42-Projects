/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:46:44 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/12/02 16:15:59 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	ft_pipex(t_args	*args, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		manage_error(args, "pipe");
	if (dup2(args->fd1, STDIN_FILENO) == -1)
		manage_error(args, "dup2");
	child_process_cmd(args, pipefd, envp);
	if (dup2(args->fd2, STDOUT_FILENO) == -1)
		manage_error(args, "dup2");
	pid = fork();
	if (pid == -1)
		manage_error(args, "fork");
	if (pid == 0)
	{
		if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
			manage_error(args, "execve");
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

void	ft_pipex_bonus_end(t_args *args, char **envp)
{
	pid_t	pid;

	if (dup2(args->fd2, STDOUT_FILENO) == -1)
		manage_error(args, "dup2");
	pid = fork();
	if (pid == -1)
		manage_error(args, "fork");
	if (pid == 0)
	{
		if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
			manage_error(args, "execve");
	}
	else
	{
		waitpid(pid, NULL, 0);
		args->cmd = args->first_cmd;
		args->cmd_path = args->first_path;
		args->command = args->first_command;
	}
}

void	ft_pipex_bonus(t_args *args, int argc, char **envp)
{
	int		x;

	x = 2;
	if (dup2(args->fd1, STDIN_FILENO) == -1)
		manage_error(args, "dup2");
	while (x < argc - 2)
	{
		manage_child(args, envp);
		args->index++;
		if (args->command->next)
		{
			args->command = args->command->next;
			args->cmd = args->cmd->next;
			args->cmd_path = args->cmd_path->next;
		}
		x++;
	}
	ft_pipex_bonus_end(args, envp);
}

t_args	*start_pipex(t_args *args, char **argv, int argc, char **envp)
{
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		here_doc_pipex(args, argv, argc);
		*args = check_args(args, envp);
		open_outfile(args);
	}
	else
	{
		init_args(args, argv, argc);
		*args = check_args(args, envp);
		open_infile(args);
		open_outfile(args);
	}
	args->first_cmd = args->cmd;
	args->first_path = args->cmd_path;
	args->first_command = args->command;
	return (args);
}

int	main(int ac, char **av, char **envp)
{
	t_args	*args;

	if (ac >= 5)
	{
		args = malloc(sizeof(t_args));
		if (!args)
			return (1);
		args = start_pipex(args, av, ac, envp);
		if (ac == 5)
			ft_pipex(args, envp);
		else
			ft_pipex_bonus(args, ac, envp);
		if (ft_strcmp(av[1], "here_doc") == 0)
			unlink(".heredoc_tmp");
		free_args(args);
	}
	else
	{
		ft_printf("Error: Few arguments passed\n");
		exit(1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:54:20 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:54:22 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Prepares the environment variable array
char	**ms_prepare_env_array(t_mshell *mshell)
{
	char	**env;

	env = ms_env_list_to_array(mshell);
	if (!env)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return (env);
}

// Handles the logic for the child process
void	ms_handle_child_process(char *path, char **args, int fd_out, char **env)
{
	if (fd_out != -1)
	{
		if (dup2(fd_out, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(fd_out);
	}
	execve(path, args, env);
	perror("execve");
	exit(EXIT_FAILURE);
}

// Handles the logic for the parent process
void	ms_handle_parent_process(pid_t pid, t_mshell *mshell)
{
	int		status;

	status = 0;
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			mshell->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			mshell->exit_status = 128 + WTERMSIG(status);
	}
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}

// Forks a new process to execute a command
void	ms_fork(t_mshell *mshell)
{
	pid_t	pid;
	char	**env;

	env = ms_prepare_env_array(mshell);
	if (!env)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		ms_handle_child_process(mshell->command.path, mshell->command.args,
			mshell->command.fd_out, env);
	}
	else if (pid > 0)
		ms_handle_parent_process(pid, mshell);
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	ms_free_env_array(env);
}

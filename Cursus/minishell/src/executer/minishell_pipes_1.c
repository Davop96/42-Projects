/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipes_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:54:54 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:54:56 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Count number of pipes in the token list
int	ms_count_pipes(t_token *tokens)
{
	int	count;

	count = 0;
	while (tokens)
	{
		if (tokens->type == TOKEN_PIPE)
			count++;
		tokens = tokens->next;
	}
	return (count);
}

// Create an array of pipes
int	**ms_create_pipes(int num_pipes)
{
	int		**pipes;
	int		i;

	pipes = ms_malloc(sizeof(int *) * num_pipes);
	i = 0;
	while (i < num_pipes)
	{
		pipes[i] = ms_malloc(sizeof(int) * 2);
		if (pipe(pipes[i]) == -1)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (pipes);
}

// Close all pipe file descriptors and free the pipes array
void	ms_close_all_pipes(int **pipes, int num_pipes)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		free(pipes[i]);
		i++;
	}
	free(pipes);
}

// Set up the correct stdin/stdout for a child in a pipeline
void	ms_setup_child_fds(int i, int num_pipes, int **pipes)
{
	int	j;

	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i < num_pipes)
		dup2(pipes[i][1], STDOUT_FILENO);
	j = 0;
	while (j < num_pipes)
	{
		close(pipes[j][0]);
		close(pipes[j][1]);
		j++;
	}
}

// Wait for all children in the pipeline
void	ms_wait_for_children(pid_t *pids, int num_cmds, t_mshell *mshell)
{
	int	status;
	int	i;

	i = 0;
	while (i < num_cmds)
	{
		waitpid(pids[i], &status, 0);
		if (i == num_cmds - 1 && WIFEXITED(status))
			mshell->exit_status = WEXITSTATUS(status);
		i++;
	}
}

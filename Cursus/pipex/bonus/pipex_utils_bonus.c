/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:46:49 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/12/02 16:15:22 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	manage_child(t_args *args, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		manage_error(args, "pipe");
	pid = fork();
	if (pid == -1)
		manage_error(args, "fork");
	if (pid == 0)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			manage_error(args, "dup2");
		close(pipefd[0]);
		if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
			manage_error(args, "execve");
	}
	else
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			manage_error(args, "dup2");
		waitpid(pid, NULL, 0);
	}
}

void	child_process_cmd(t_args *args, int pipefd[2], char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		manage_error(args, "fork");
	if (pid == 0)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			manage_error(args, "dup2");
		close(pipefd[0]);
		if (execve(args->cmd_path->content, args->command->cmd, envp) == -1)
			manage_error(args, "execve");
	}
	else
	{
		close(pipefd[1]);
		if (dup2(pipefd[0], STDIN_FILENO) == -1)
			manage_error(args, "dup2");
		waitpid(pid, NULL, 0);
		args->cmd_path = args->cmd_path->next;
		args->command = args->command->next;
	}
}

void	ft_add_cmd_back(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	last = *lst;
	if (!last)
		*lst = new;
	else
	{
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

t_cmd	*ft_new_command(char *content)
{
	t_cmd	*new;

	new = NULL;
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	if (new)
	{
		new->cmd = ft_split(content, ' ');
		new->next = NULL;
	}
	return (new);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	x;

	x = 0;
	while (s1[x] || s2[x])
	{
		if (s1[x] != s2[x])
			return ((unsigned char)s1[x] - (unsigned char)s2[x]);
		x++;
	}
	return (0);
}

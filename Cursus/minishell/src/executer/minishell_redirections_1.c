/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirections_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:55:26 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:55:29 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Helper function to handle perror and close fd_in
int	ms_perror_input(const char *message, int fd_in)
{
	perror(message);
	close(fd_in);
	return (-1);
}

// Handles output redirections (overwrite or append) for a command
int	ms_handle_output_redirection(t_token *cmd_token,
	int *fd_out, t_mshell *mshell)
{
	if (cmd_token->next == NULL || cmd_token->next->type != TOKEN_WORD)
	{
		ms_print_parse_error(cmd_token->type, mshell);
		return (-1);
	}
	if (cmd_token->type == TOKEN_REDIRECT_OUT)
		*fd_out = open(cmd_token->next->value, O_WRONLY
				| O_CREAT | O_TRUNC, 0644);
	else if (cmd_token->type == TOKEN_APPEND)
		*fd_out = open(cmd_token->next->value, O_WRONLY
				| O_CREAT | O_APPEND, 0644);
	if (*fd_out == -1)
	{
		perror(cmd_token->next->value);
		mshell->exit_status = 1;
		return (-1);
	}
	if (dup2(*fd_out, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		close(*fd_out);
		return (-1);
	}
	close(*fd_out);
	return (0);
}

// Handles input redirection for a command
int	ms_handle_input_redirection(t_token *cmd_token, int *saved_stdin)
{
	int	fd_in;

	fd_in = open(cmd_token->next->value, O_RDONLY);
	if (fd_in == -1)
	{
		perror(cmd_token->next->value);
		return (-1);
	}
	if (*saved_stdin == -1)
	{
		*saved_stdin = dup(STDIN_FILENO);
		if (*saved_stdin == -1)
			return (ms_perror_input("dup", fd_in));
	}
	if (dup2(fd_in, STDIN_FILENO) == -1)
		return (ms_perror_input("dup2", fd_in));
	close(fd_in);
	return (0);
}

// Restores the original STDIN after input redirection
void	ms_restore_stdin(int *saved_stdin)
{
	if (*saved_stdin != -1)
	{
		if (dup2(*saved_stdin, STDIN_FILENO) == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(*saved_stdin);
		*saved_stdin = -1;
	}
}

// Restores the original STDOUT
void	ms_restore_stdout(int saved_stdout)
{
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdout);
}

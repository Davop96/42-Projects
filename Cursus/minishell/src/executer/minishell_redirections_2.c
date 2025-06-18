/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirections_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:55:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:55:36 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Handles a single output redirection (overwrite or append)
int	ms_process_output_redirection(t_token *cmd_token, t_mshell *mshell)
{
	if (ms_handle_output_redirection(cmd_token,
			&mshell->command.fd_out, mshell) == -1)
		return (-1);
	return (0);
}

// Handles a single input redirection
int	ms_process_input_redirection(t_token *cmd_token,
	int *saved_stdin, t_mshell *mshell)
{
	if (cmd_token->next == NULL || cmd_token->next->type != TOKEN_WORD)
	{
		ms_print_parse_error(cmd_token->type, mshell);
		return (-1);
	}
	if (ms_handle_input_redirection(cmd_token, saved_stdin) == -1)
	{
		mshell->exit_status = 1;
		return (-1);
	}
	return (0);
}

// Processes a single token for redirection
int	ms_process_redirection_token(t_token *cmd_token,
	t_mshell *mshell, int *saved_stdin)
{
	if (cmd_token->type == TOKEN_REDIRECT_OUT
		|| cmd_token->type == TOKEN_APPEND)
		return (ms_process_output_redirection(cmd_token, mshell));
	else if (cmd_token->type == TOKEN_REDIRECT_IN)
		return (ms_process_input_redirection(cmd_token, saved_stdin, mshell));
	else if (cmd_token->type == TOKEN_HEREDOC)
		return (0);
	return (0);
}

// Main function to handle all redirections for a command
void	ms_handle_redirections(t_mshell *mshell, t_token *command_start,
	t_token *current_token)
{
	t_token	*cmd_token;
	int		saved_stdin;

	mshell->red_fail = 0;
	saved_stdin = -1;
	cmd_token = command_start;
	mshell->command.fd_out = -1;
	while (cmd_token != NULL && cmd_token != current_token)
	{
		if (ms_process_redirection_token(cmd_token, mshell, &saved_stdin) == -1)
		{
			mshell->command.saved_stdin = saved_stdin;
			mshell->red_fail = 1;
			mshell->exit_status = 1;
			return ;
		}
		cmd_token = cmd_token->next;
	}
	mshell->command.saved_stdin = saved_stdin;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:53:47 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:53:50 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Checks and extracts the command path and arguments from tokens
int	ms_check_command(t_mshell *mshell)
{
	return (mshell->command.args && mshell->command.args[0]);
}

// Handles the execution of a command, including builtins and external commands
void	ms_handle_command(t_mshell *mshell)
{
	int		saved_stdout;
	int		is_builtin;

	saved_stdout = dup(STDOUT_FILENO);
	if (ms_check_command(mshell))
	{
		if (mshell->command.fd_out != -1)
		{
			dup2(mshell->command.fd_out, STDOUT_FILENO);
			close(mshell->command.fd_out);
		}
		is_builtin = ms_builtin_main(
				mshell->command.args,
				mshell->command.fd_out, mshell,
				&mshell->env_list
				);
		dup2(saved_stdout, STDOUT_FILENO);
		close(saved_stdout);
		if (is_builtin)
			return ;
		ms_fork(mshell);
	}
}

// Handles pipelines or commands
void	ms_handle_pipeline_or_command(t_mshell *mshell, t_token **command_start,
	t_token **current_token)
{
	if ((*current_token)->type == TOKEN_PIPE || (*current_token)->next
		== NULL)
	{
		ms_check_execution(mshell, *command_start, *current_token);
		*command_start = (*current_token)->next;
	}
}

// Frees all dynamically allocated strings in the command's args array
void	ms_free_command_args(t_command *command)
{
	int	i;

	i = 0;
	while (command->args[i])
	{
		free(command->args[i]);
		command->args[i] = NULL;
		i++;
	}
}

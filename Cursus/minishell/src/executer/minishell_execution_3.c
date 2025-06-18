/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execution_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:54:14 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:54:16 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//Prepare tokens
static t_token	*ms_prepare_tokens(t_mshell *mshell)
{
	ms_update_pwd(&mshell->env_list);
	ms_expand_variables_in_tokens(mshell->env_list, mshell->tokens,
		mshell->exit_status);
	ms_remove_empty_tokens(&mshell->tokens);
	return (mshell->tokens);
}

//Handle special cases and heredocs
static int	ms_handle_special_cases_and_heredoc(t_mshell *mshell,
	t_token *command_start, t_token *current_token)
{
	if (ms_execute_special_cases(mshell, command_start))
		return (1);
	ms_handle_heredoc_tokens(mshell, current_token);
	if (ms_handle_cat_with_heredoc(mshell, command_start))
		return (1);
	return (0);
}

//Prepare command arguments and path
static void	ms_prepare_command_args(t_mshell *mshell, t_token *command_start)
{
	char	**tmp_argv;
	int		i;

	i = 0;
	ms_free_command_args(&mshell->command);
	tmp_argv = ms_build_argv_for_redirection(command_start);
	while (tmp_argv && tmp_argv[i] && i < 255)
	{
		mshell->command.args[i] = tmp_argv[i];
		i++;
	}
	mshell->command.args[i] = NULL;
	if (tmp_argv)
		free(tmp_argv);
	if (mshell->command.args[0])
		mshell->command.path = ft_strdup(mshell->command.args[0]);
	else
		mshell->command.path = NULL;
}

// Main function to check execution
void	ms_check_execution(t_mshell *mshell, t_token *command_start,
	t_token *current_token)
{
	command_start = ms_prepare_tokens(mshell);
	if (!command_start)
	{
		mshell->exit_status = 0;
		return ;
	}
	if (ms_handle_special_cases_and_heredoc(mshell, command_start,
			current_token))
		return ;
	ms_handle_redirections(mshell, command_start, current_token);
	ms_prepare_command_args(mshell, command_start);
	if (ms_builtin_main(mshell->command.args, mshell->command.fd_out, mshell,
			&mshell->env_list))
	{
		ms_restore_stdin(&mshell->command.saved_stdin);
		return ;
	}
	ms_execute_command_logic(mshell);
}

// Executes a pipeline of commands
void	ms_execute_command(t_mshell *mshell)
{
	t_token		*current_token;
	t_token		*command_start;
	int			saved_stdout;

	if (ms_count_pipes(mshell->tokens) > 0)
	{
		ms_execute_pipeline(mshell);
		return ;
	}
	current_token = mshell->tokens;
	command_start = mshell->tokens;
	saved_stdout = dup(STDOUT_FILENO);
	while (current_token != NULL)
	{
		mshell->command.fd_out = -1;
		ms_handle_pipeline_or_command(mshell, &command_start, &current_token);
		current_token = current_token->next;
	}
	ms_restore_stdout(saved_stdout);
	if (mshell->command.heredoc_fd != -1)
	{
		close(mshell->command.heredoc_fd);
		mshell->command.heredoc_fd = -1;
	}
}

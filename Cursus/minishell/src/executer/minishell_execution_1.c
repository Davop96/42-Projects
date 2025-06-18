/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execution_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:53:58 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:54:01 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//Check if path is a directory or not executable
static int	ms_check_path_errors(const char *path, t_mshell *mshell)
{
	struct stat	statbuf;

	if (stat(path, &statbuf) == 0)
	{
		if (S_ISDIR(statbuf.st_mode))
		{
			ms_ft_stderr(path);
			ms_ft_stderr(": Is a directory\n");
			mshell->exit_status = 126;
			return (1);
		}
		if (access(path, X_OK) != 0)
		{
			ms_ft_stderr(path);
			ms_ft_stderr(": Permission denied\n");
			mshell->exit_status = 126;
			return (1);
		}
	}
	return (0);
}

//Handle not found error for path with slash
static void	ms_handle_no_such_file(const char *path, t_mshell *mshell)
{
	ms_ft_stderr(path);
	ms_ft_stderr(": No such file or directory\n");
	mshell->exit_status = 127;
}

//Handle not found error for command without slash
static void	ms_handle_command_not_found(const char *path, t_mshell *mshell)
{
	ms_print_command_not_found(path, mshell);
	mshell->exit_status = 127;
}

// Main function to prepare the executables
char	*ms_prepare_executable(t_mshell *mshell)
{
	char	*executable;

	if (ft_strchr(mshell->command.path, '/'))
	{
		if (ms_check_path_errors(mshell->command.path, mshell))
			return (NULL);
		executable = ms_find_executable(mshell->command.path, mshell->env_list);
		if (!executable)
			ms_handle_no_such_file(mshell->command.path, mshell);
		return (executable);
	}
	executable = ms_find_executable(mshell->command.path, mshell->env_list);
	if (!executable)
		ms_handle_command_not_found(mshell->command.path, mshell);
	return (executable);
}

// Handles special errors and invalid tokens
int	ms_execute_special_cases(t_mshell *mshell, t_token *command_start)
{
	if (ms_print_special_errors(command_start->value, mshell))
		return (1);
	if (command_start->type == TOKEN_PIPE
		|| command_start->type == TOKEN_SEMICOLON)
	{
		ms_print_parse_error(command_start->type, mshell);
		return (1);
	}
	return (0);
}

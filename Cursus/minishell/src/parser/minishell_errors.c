/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:52:14 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:52:17 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Prints a "command not found" error message
void	ms_print_command_not_found(const char *command, t_mshell *mshell)
{
	ms_ft_stderr(command);
	ms_ft_stderr(": command not found\n");
	mshell->exit_status = 127;
}

// Handles special error cases for invalid input
int	ms_print_special_errors(char *input, t_mshell *mshell)
{
	if (ms_ft_strcmp(input, "..") == 0)
	{
		ms_ft_stderr("command not found: ..\n");
		mshell->exit_status = 127;
		return (1);
	}
	else if (ms_ft_strcmp(input, "\"\"\"") == 0)
	{
		ms_ft_stderr("incorrect input detected\n");
		mshell->exit_status = 2;
		return (1);
	}
	else if (ft_strlen(input) == 0 || ms_ft_str_is_space(input))
	{
		mshell->exit_status = 0;
		return (1);
	}
	return (0);
}

void	ms_update_exit_status_on_signal(int sig, t_mshell *mshell)
{
	if (sig == SIGINT)
		mshell->exit_status = 130;
	else if (sig == SIGQUIT)
		mshell->exit_status = 131;
}

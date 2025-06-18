/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execution_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:54:06 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:54:08 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//Clean up and reset command state
static void	ms_cleanup_command(t_mshell *mshell)
{
	ms_restore_stdin(&mshell->command.saved_stdin);
	ms_free_command_args(&mshell->command);
	free(mshell->command.path);
	mshell->command.path = NULL;
}

//Prepare the executable path and handle errors
static char	*ms_precheck_exe(t_mshell *mshell)
{
	char	*prepared_path;

	prepared_path = ms_prepare_executable(mshell);
	if (!prepared_path)
	{
		ms_cleanup_command(mshell);
		return (NULL);
	}
	return (prepared_path);
}

// Main function, now divided
void	ms_execute_command_logic(t_mshell *mshell)
{
	char	*prepared_path;

	if (mshell->red_fail)
	{
		ms_cleanup_command(mshell);
		return ;
	}
	prepared_path = ms_precheck_exe(mshell);
	if (!prepared_path)
		return ;
	free(mshell->command.path);
	mshell->command.path = prepared_path;
	ms_handle_command(mshell);
	ms_cleanup_command(mshell);
}

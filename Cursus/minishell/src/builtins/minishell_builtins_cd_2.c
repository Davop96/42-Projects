/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins_cd_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:13:02 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:13:04 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//Count arguments in args array
static int	ms_count_args(char **args)
{
	int	count;

	count = 0;
	while (args[count])
		count++;
	return (count);
}

//Handle "too many arguments" error
static int	ms_cd_too_many_args(t_mshell *mshell)
{
	ms_ft_stderr("bash: cd: too many arguments\n");
	mshell->exit_status = 1;
	return (1);
}

//Handle changing to home directory
static int	ms_cd_handle_home(t_var *env_list, t_mshell *mshell)
{
	if (ms_cd_to_home(env_list) != 0)
	{
		mshell->exit_status = 1;
		return (1);
	}
	return (0);
}

//Handle changing to a specific path
static int	ms_cd_handle_path(char *path, t_mshell *mshell)
{
	if (ms_cd_to_path(path) != 0)
	{
		mshell->exit_status = 1;
		return (1);
	}
	return (0);
}

// Main cd builtin, now divided
void	ms_builtin_cd(char **args, t_var *env_list, t_mshell *mshell)
{
	int	argc;

	argc = ms_count_args(args);
	if (argc > 2)
	{
		ms_cd_too_many_args(mshell);
		return ;
	}
	if (args[1] == NULL)
	{
		if (ms_cd_handle_home(env_list, mshell))
			return ;
	}
	else
	{
		if (ms_cd_handle_path(args[1], mshell))
			return ;
	}
	ms_update_pwd(&env_list);
	mshell->exit_status = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_manager.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:12:48 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:12:50 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Determines if the command is a builtin and executes it
int	ms_read_builtins(char **args, t_mshell *mshell, t_var **head)
{
	if (args[0] == NULL)
		return (0);
	if (ms_ft_strcmp(args[0], "echo") == 0)
		ms_builtin_echo(args);
	else if (ms_ft_strcmp(args[0], "cd") == 0)
		ms_builtin_cd(args, *head, mshell);
	else if (ms_ft_strcmp(args[0], "pwd") == 0)
		ms_builtin_pwd();
	else if (ms_ft_strcmp(args[0], "exit") == 0)
		ms_builtin_exit(mshell);
	else if (ms_ft_strcmp(args[0], "export") == 0)
		ms_builtin_export(mshell, head, args);
	else if (ms_ft_strcmp(args[0], "unset") == 0)
		ms_builtin_unset(mshell, head, args);
	else if (ms_ft_strcmp(args[0], "env") == 0)
		ms_builtin_env(*head);
	else
		return (0);
	return (1);
}

// Executes a builtin command and handles output redirection
int	ms_builtin_main(char **args, int fd_out, t_mshell *mshell, t_var **head)
{
	int	saved_stdout;

	saved_stdout = -1;
	if (fd_out != -1)
	{
		saved_stdout = dup(STDOUT_FILENO);
		if (dup2(fd_out, STDOUT_FILENO) == -1)
		{
			perror("dup2");
			return (1);
		}
	}
	if (!ms_read_builtins(args, mshell, head))
	{
		if (saved_stdout != -1)
			dup2(saved_stdout, STDOUT_FILENO);
		return (0);
	}
	if (saved_stdout != -1)
		dup2(saved_stdout, STDOUT_FILENO);
	return (1);
}

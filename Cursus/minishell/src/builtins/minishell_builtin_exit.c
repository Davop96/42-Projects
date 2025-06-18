/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:12:34 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:12:43 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Helper: Check if a string is a valid numeric argument for exit
static int	ms_is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// Helper: Print error and exit for non-numeric argument
static void	ms_exit_numeric_error(const char *arg, t_mshell *mshell)
{
	ms_ft_stderr("exit: ");
	ms_ft_stderr((char *)arg);
	ms_ft_stderr(": numeric argument required\n");
	rl_clear_history();
	ms_free_main(mshell);
	exit(2);
}

// Helper: Print error for too many arguments
static void	ms_exit_too_many_args(t_mshell *mshell)
{
	ms_ft_stderr("exit: too many arguments\n");
	mshell->exit_status = 1;
}

// Main builtin exit
void	ms_builtin_exit(t_mshell *mshell)
{
	int		exit_code;
	char	*arg;

	exit_code = mshell->exit_status;
	printf("exit\n");
	if (mshell->command.args[1])
	{
		arg = mshell->command.args[1];
		if (!ms_is_numeric(arg))
			ms_exit_numeric_error(arg, mshell);
		if (mshell->command.args[2])
		{
			ms_exit_too_many_args(mshell);
			return ;
		}
		exit_code = ft_atoi(arg);
	}
	rl_clear_history();
	ms_free_main(mshell);
	exit(exit_code);
}

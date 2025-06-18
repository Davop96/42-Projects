/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:49 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:50 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Handle "Ctrl-C" (SIGINT)
void	ms_handle_sigint(int sig, t_mshell *mshell)
{
	rl_replace_line("", 0);
	rl_on_new_line();
	write(STDOUT_FILENO, "\n", 1);
	rl_redisplay();
	ms_update_exit_status_on_signal(sig, mshell);
}

// Handle "Ctrl-\" (SIGQUIT)
void	ms_handle_sigquit(int sig)
{
	(void)sig;
}

// Handle "Ctrl-D" (EOF)
void	ms_handle_eof(t_mshell *mshell)
{
	printf("exit\n");
	rl_clear_history();
	ms_free_main(mshell);
	exit(0);
}

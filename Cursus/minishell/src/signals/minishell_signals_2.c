/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:55 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:56 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static t_mshell	*g_mshell = NULL;

// Wrapper for signal handler
void	ms_handle_sigint_wrapper(int sig)
{
	if (g_mshell)
		ms_handle_sigint(sig, g_mshell);
}

// Main signal function
void	ms_signals_main(t_mshell *mshell)
{
	g_mshell = mshell;
	signal(SIGINT, ms_handle_sigint_wrapper);
	signal(SIGQUIT, ms_handle_sigquit);
	signal(SIGQUIT, SIG_IGN);
}

void	ms_heredoc_sigint_handler(int sig)
{
	(void)sig;
	if (g_mshell)
		g_mshell->heredoc_interrupted = 1;
	write(STDOUT_FILENO, "\n", 1);
	rl_done = 1;
}

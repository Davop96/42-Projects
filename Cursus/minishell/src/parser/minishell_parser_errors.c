/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser_errors.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:52:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:52:25 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ms_print_pipe_error(t_mshell *mshell)
{
	ms_ft_stderr("syntax error near unexpected token `|'\n");
	mshell->exit_status = 2;
}

static void	ms_print_semicolon_error(t_mshell *mshell)
{
	ms_ft_stderr("syntax error near unexpected token `;'\n");
	mshell->exit_status = 2;
}

static void	ms_print_redirect_error(t_mshell *mshell)
{
	ms_ft_stderr("syntax error near unexpected token `newline'\n");
	mshell->exit_status = 2;
}

static void	ms_print_heredoc_error(t_mshell *mshell)
{
	ms_ft_stderr("parse error near '<<'\n");
	mshell->exit_status = 2;
}

// Prints a parse error message based on the token type
void	ms_print_parse_error(t_token_type token_type, t_mshell *mshell)
{
	if (token_type == TOKEN_PIPE)
		ms_print_pipe_error(mshell);
	else if (token_type == TOKEN_SEMICOLON)
		ms_print_semicolon_error(mshell);
	else if (token_type == TOKEN_REDIRECT_IN
		|| token_type == TOKEN_REDIRECT_OUT)
		ms_print_redirect_error(mshell);
	else if (token_type == TOKEN_HEREDOC)
		ms_print_heredoc_error(mshell);
	else
	{
		ms_ft_stderr("syntax error\n");
		mshell->exit_status = 2;
	}
}

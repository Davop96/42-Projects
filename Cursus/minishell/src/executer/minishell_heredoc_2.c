/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_heredoc_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:54:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:57:58 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Creates a pipe and handles errors
int	ms_create_pipe(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	return (0);
}

// Reads heredoc lines and writes them to the pipe
static	void	ms_heredoc_loop(int write_fd,
	const char *delimiter, t_mshell *mshell)
{
	char	*line;

	while (1)
	{
		line = readline(BOLD_TEXT "heredoc> " RESET_TEXT);
		if (mshell->heredoc_interrupted || line == NULL)
		{
			if (line)
				free(line);
			break ;
		}
		if (ms_ft_strcmp(line, delimiter) == 0)
		{
			free(line);
			break ;
		}
		write(write_fd, line, ft_strlen(line));
		write(write_fd, "\n", 1);
		free(line);
	}
}

// Prepares delimiter, sets up signal handler, and calls the heredoc loop
void	ms_read_heredoc_input(int write_fd,
	t_token *delimiter_token, t_mshell *mshell)
{
	void	(*old_handler)(int);
	char	*delimiter;

	mshell->heredoc_interrupted = 0;
	old_handler = signal(SIGINT, ms_heredoc_sigint_handler);
	if (delimiter_token->quote_type == QUOTE_NONE)
		delimiter = ms_replace_env_vars(mshell->env_list,
				delimiter_token->value, mshell->exit_status);
	else
		delimiter = ft_strdup(delimiter_token->value);
	ms_heredoc_loop(write_fd, delimiter, mshell);
	free(delimiter);
	signal(SIGINT, old_handler);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_heredoc_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:54:27 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:54:29 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Handles the heredoc redirection by reading input until a delimiter is reached
void	ms_handle_heredoc(t_token *token, int *heredoc_fd, t_mshell *mshell)
{
	int		pipefd[2];

	if (ms_create_pipe(pipefd) == -1)
		return ;
	ms_read_heredoc_input(pipefd[1], token->next, mshell);
	rl_clear_history();
	close(pipefd[1]);
	*heredoc_fd = pipefd[0];
}

// Processes all heredoc tokens in a command and sets up the input redirection
void	ms_handle_heredoc_tokens(t_mshell *mshell, t_token *end_token)
{
	t_token	*token;

	token = mshell->tokens;
	mshell->command.heredoc_fd = -1;
	while (token != NULL)
	{
		if (token == end_token)
			break ;
		if (token->type == TOKEN_HEREDOC)
		{
			ms_handle_heredoc(token, &mshell->command.heredoc_fd, mshell);
			token = token->next;
		}
		token = token->next;
	}
}

// Handles the special case of "cat" with heredoc
int	ms_handle_cat_with_heredoc(t_mshell *mshell, t_token *command_start)
{
	char	buffer[1024];
	ssize_t	bytes_read;

	if (command_start->type == TOKEN_WORD
		&& ms_ft_strcmp(command_start->value, "cat") == 0
		&& command_start->next != NULL
		&& command_start->next->type == TOKEN_HEREDOC)
	{
		bytes_read = read(mshell->command.heredoc_fd, buffer,
				sizeof(buffer));
		while (bytes_read > 0)
		{
			write(STDOUT_FILENO, buffer, bytes_read);
			bytes_read = read(mshell->command.heredoc_fd, buffer,
					sizeof(buffer));
		}
		ms_restore_stdin(&mshell->command.saved_stdin);
		close(mshell->command.heredoc_fd);
		mshell->command.heredoc_fd = -1;
		return (1);
	}
	return (0);
}

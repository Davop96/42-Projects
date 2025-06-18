/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipes_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:55:03 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:55:05 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Counts the number of arguments before a pipe, skipping redirections
static int	ms_count_argv_args_pipe(t_token *pipe)
{
	int			count;
	t_token		*cur;

	count = 0;
	cur = pipe;
	while (cur && cur->type != TOKEN_PIPE)
	{
		if (cur->type == TOKEN_REDIRECT_IN || cur->type == TOKEN_REDIRECT_OUT
			|| cur->type == TOKEN_APPEND || cur->type == TOKEN_HEREDOC)
		{
			cur = cur->next;
			if (cur)
				cur = cur->next;
			continue ;
		}
		count++;
		cur = cur->next;
	}
	return (count);
}

// Fills argv with arguments before a pipe, skipping redirections
static void	ms_fill_argv_for_pipe(char **argv, t_token *pipe)
{
	t_token	*cur;
	int		i;

	cur = pipe;
	i = 0;
	while (cur && cur->type != TOKEN_PIPE)
	{
		if (cur->type == TOKEN_REDIRECT_IN || cur->type == TOKEN_REDIRECT_OUT
			|| cur->type == TOKEN_APPEND || cur->type == TOKEN_HEREDOC)
		{
			cur = cur->next;
			if (cur)
				cur = cur->next;
			continue ;
		}
		argv[i++] = ft_strdup(cur->value);
		cur = cur->next;
	}
	argv[i] = NULL;
}

// Allocates and fills argv, skipping redirections and their targets
char	**ms_build_argv_for_pipe(t_token *pipe)
{
	int		count;
	char	**argv;

	count = ms_count_argv_args_pipe(pipe);
	argv = ms_malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	ms_fill_argv_for_pipe(argv, pipe);
	return (argv);
}

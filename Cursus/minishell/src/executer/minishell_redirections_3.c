/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_redirections_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:55:41 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:55:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Counts the number of arguments before a pipe, skipping redirections
static int	ms_count_argv_args(t_token *segment)
{
	int		count;
	t_token	*cur;

	count = 0;
	cur = segment;
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

// Allocates and fills argv, skipping redirections
char	**ms_build_argv_for_redirection(t_token *segment)
{
	int		count;
	char	**argv;
	t_token	*cur;
	int		i;

	count = ms_count_argv_args(segment);
	argv = ms_malloc(sizeof(char *) * (count + 1));
	cur = segment;
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
	return (argv);
}

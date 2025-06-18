/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_collector.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:51:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:51:08 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Copies a quoted substring (without the quotes) into buffer.
// Advances *input past the closing quote.
static void	ms_copy_quoted_part(char **input, char *buffer, int *pos,
	t_quote_type *quote_type)
{
	char	quote_char;

	quote_char = **input;
	if (quote_char == '\'')
		*quote_type = QUOTE_SINGLE;
	else
		*quote_type = QUOTE_DOUBLE;
	(*input)++;
	while (**input && **input != quote_char)
		buffer[(*pos)++] = *(*input)++;
	if (**input == quote_char)
		(*input)++;
}

// Copies an unquoted character into buffer and advances *input.
static void	ms_copy_unquoted_char(char **input, char *buffer, int *pos)
{
	buffer[(*pos)++] = *(*input)++;
}

// Collects a token, merging quoted and unquoted parts as bash does.
char	*ms_collect_token(char **input, t_quote_type *quote_type)
{
	char	buffer[4096];
	int		pos;
	char	*res;

	pos = 0;
	*quote_type = QUOTE_NONE;
	while (**input && !ms_ft_is_space(**input) && **input != '|' && **input
		!= '<' && **input != '>' && **input != ';')
	{
		if (**input == '\'' || **input == '"')
			ms_copy_quoted_part(input, buffer, &pos, quote_type);
		else
			ms_copy_unquoted_char(input, buffer, &pos);
	}
	buffer[pos] = '\0';
	res = ft_strdup(buffer);
	return (res);
}

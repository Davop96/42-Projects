/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_tokenizer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:51:51 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:51:53 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Adds the final token to the token list.
// Extracts the token from the input and adds it to the list.
void	ms_add_final_token(char **start, char **end, t_token **tokens)
{
	char	*token;

	if (*start != *end)
	{
		token = ms_ft_strndup(*start, *end - *start);
		ms_add_token(tokens, token, ms_get_token_type(token), QUOTE_NONE);
	}
}

// Processes a token in the input.
// Handles quoted strings, spaces, and special characters.
void	ms_process_token(char **start, char **end, t_token **tokens)
{
	char			*token;
	t_quote_type	quote_type;

	if (ms_ft_is_space(**end))
	{
		ms_handle_spaces(start, end, tokens);
	}
	else if (**end == '|' || **end == '<' || **end == '>' || **end == ';')
	{
		ms_handle_special_chars(start, end, tokens);
	}
	else
	{
		token = ms_collect_token(end, &quote_type);
		ms_add_token(tokens, token, TOKEN_WORD, quote_type);
		free(token);
		*start = *end;
	}
}

// Tokenizes the input string.
// Splits the input into tokens and returns the token list.
t_token	*ms_tokenize(char *input)
{
	t_token	*tokens;
	char	*start;
	char	*end;

	input = ms_handle_incompletes(input);
	if (!input)
		return (NULL);
	tokens = NULL;
	start = input;
	end = input;
	while (*end)
	{
		ms_process_token(&start, &end, &tokens);
	}
	ms_add_final_token(&start, &end, &tokens);
	free(input);
	return (tokens);
}

// Frees the memory allocated for the token list.
void	ms_free_tokens(t_token *tokens)
{
	t_token	*current;
	t_token	*next;

	current = tokens;
	while (current)
	{
		next = current->next;
		if (current->value)
			free(current->value);
		current->value = NULL;
		free(current);
		current = next;
	}
}

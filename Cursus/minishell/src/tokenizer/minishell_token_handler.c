/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_handler.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:51:23 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:51:26 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Handles spaces in the input.
// Extracts the token before the space and adds it to the token list.
void	ms_handle_spaces(char **start, char **end, t_token **tokens)
{
	char	*token;

	if (*start != *end)
	{
		token = ms_ft_strndup(*start, *end - *start);
		ms_add_token(tokens, token, ms_get_token_type(token),
			QUOTE_NONE);
	}
	(*end)++;
	*start = *end;
}

/* Handles special characters in the input (e.g., |, <, >).
Extracts the token before the special character and adds it to the token list.
Adds the special character as a separate token. */
void	ms_handle_special_chars(char **start, char **end, t_token **tokens)
{
	char	*token_str;
	char	token[3];

	if (*start != *end)
	{
		token_str = ms_ft_strndup(*start, *end - *start);
		ms_add_token(tokens, token_str, ms_get_token_type(token_str),
			QUOTE_NONE);
	}
	else
	{
		token[0] = **end;
		if (*(*end + 1) == token[0])
			token[1] = *(*end + 1);
		else
			token[1] = '\0';
		token[2] = '\0';
		ms_add_token(tokens, token, ms_get_token_type(token),
			QUOTE_NONE);
		if (token[1] != '\0')
			*end += 2;
		else
			*end += 1;
	}
	*start = *end;
}

// Handles incomplete input, such as unclosed quotes.
// Prompts the user for additional input until the command is complete.
char	*ms_handle_incompletes(char *input)
{
	char	*new_input;
	char	*processed_input;

	while (ms_has_unclosed_quote(input))
	{
		new_input = ms_prompt_for_additional_input(input);
		if (!new_input)
			return (NULL);
		input = new_input;
	}
	processed_input = ms_remove_escapes(input);
	return (processed_input);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_creator.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:51:14 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:51:17 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* Creates a new token with the given value and type.
Allocates memory for the token and its value,
and initializes the token's fields. */
t_token	*ms_create_token(char *value, t_token_type type,
	t_quote_type quote_type)
{
	t_token	*token;

	token = ms_malloc(sizeof(t_token));
	token->value = ft_strdup(value);
	token->type = type;
	token->quote_type = quote_type;
	token->next = NULL;
	return (token);
}

// Adds a new token to the end of the token list.
// If the list is empty, the new token becomes the first token.
void	ms_add_token(t_token **tokens, char *value, t_token_type type,
	t_quote_type quote_type)
{
	t_token	*new_token;
	t_token	*temp;

	new_token = ms_create_token(value, type, quote_type);
	if (*tokens == NULL)
	{
		*tokens = new_token;
	}
	else
	{
		temp = *tokens;
		while (temp->next)
			temp = temp->next;
		temp->next = new_token;
	}
}

// Determines the type of a token based on its value.
// Returns the corresponding token type.
t_token_type	ms_get_token_type(char *token)
{
	if (ms_ft_strcmp(token, "|") == 0)
		return (TOKEN_PIPE);
	if (ms_ft_strcmp(token, "<") == 0)
		return (TOKEN_REDIRECT_IN);
	if (ms_ft_strcmp(token, ">") == 0)
		return (TOKEN_REDIRECT_OUT);
	if (ms_ft_strcmp(token, "<<") == 0)
		return (TOKEN_HEREDOC);
	if (ms_ft_strcmp(token, ">>") == 0)
		return (TOKEN_APPEND);
	if (ms_ft_strcmp(token, ";") == 0)
		return (TOKEN_SEMICOLON);
	return (TOKEN_WORD);
}

// Removes escape characters (backslashes) from the input string.
char	*ms_remove_escapes(const char *input)
{
	char	*result;
	int		i;
	int		j;

	result = ms_malloc(ft_strlen(input) + 1);
	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] == '\\' && input[i + 1] != '\0')
		{
			i++;
		}
		result[j++] = input[i++];
	}
	result[j] = '\0';
	return (result);
}

// Prompts the user for additional input and appends it to the current input.
char	*ms_prompt_for_additional_input(char *input)
{
	char	*additional_input;
	char	*temp_input;
	char	*new_input;

	additional_input = readline("> ");
	if (!additional_input)
	{
		printf("unexpected EOF while looking for matching \n");
		printf("syntax error: unexpected end of file\n");
		return (NULL);
	}
	temp_input = ft_strjoin(input, "\n");
	new_input = ft_strjoin(temp_input, additional_input);
	free(temp_input);
	free(additional_input);
	return (new_input);
}

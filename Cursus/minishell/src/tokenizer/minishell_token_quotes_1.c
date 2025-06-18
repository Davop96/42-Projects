/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_quotes_1.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:51:33 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:51:36 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Counts the number of unescaped quotes in the input.
int	ms_count_unescaped_quotes(const char *input)
{
	int	quote_count;
	int	i;

	quote_count = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '\\')
		{
			i++;
			if (input[i] != '\0')
				i++;
			continue ;
		}
		if (input[i] == '\'' || input[i] == '"')
			quote_count++;
		i++;
	}
	return (quote_count);
}

// Extracts and duplicates the text before the next quote
char	*ms_handle_text_before_quotes(char **start, char **end)
{
	char	*before_quotes;

	before_quotes = ms_ft_strndup(*start, *end - *start);
	*start = *end;
	return (before_quotes);
}

// Frees before_quotes and result, and returns an empty string if is empty
char	*ms_free_quotes(char *before_quotes, char *result, char *final_result)
{
	free(before_quotes);
	free(result);
	if (ft_strlen(final_result) == 0)
	{
		free(final_result);
		return (ft_strdup(""));
	}
	return (final_result);
}

// Returns 1 if there is an unclosed quote, 0 otherwise
int	ms_has_unclosed_quote(const char *input)
{
	int	in_single;
	int	in_double;

	in_single = 0;
	in_double = 0;
	while (*input)
	{
		if (*input == '\'' && !in_double)
			in_single = !in_single;
		else if (*input == '"' && !in_single)
			in_double = !in_double;
		input++;
	}
	return (in_single || in_double);
}

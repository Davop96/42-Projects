/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_token_quotes_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:51:41 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:51:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Extracts the quoted content (without quotes) and advances *end
static char	*ms_extract_quoted_content(char **end, char quote)
{
	char	*start_quote;
	char	*result;

	start_quote = *end;
	while (**end && **end != quote)
		(*end)++;
	result = ms_ft_strndup(start_quote, *end - start_quote);
	if (**end)
		(*end)++;
	return (result);
}

// Extracts any immediate non-space, non-special characters after the quote
static char	*ms_extract_after_quotes(char **end)
{
	char	*start;
	char	*res;

	start = *end;
	while (**end && !ms_ft_is_space(**end) && **end != '|' && **end
		!= '<' && **end != '>' && **end != ';')
		(*end)++;
	if (*end > start)
		res = ms_ft_strndup(start, *end - start);
	else
		res = ft_strdup("");
	return (res);
}

// Handles quoted strings in the input, merges before/after text
char	*ms_handle_quotes(char **end, t_quote_type *quote_type, char **start)
{
	char	quote;
	char	*before_quotes;
	char	*joined;
	char	*after_quotes;
	char	*tmp;

	quote = **end;
	if (quote == '\'')
		*quote_type = QUOTE_SINGLE;
	else
		*quote_type = QUOTE_DOUBLE;
	before_quotes = ms_handle_text_before_quotes(start, end);
	(*end)++;
	joined = ms_extract_quoted_content(end, quote);
	after_quotes = ms_extract_after_quotes(end);
	tmp = ft_strjoin(joined, after_quotes);
	free(after_quotes);
	free(joined);
	joined = ft_strjoin(before_quotes, tmp);
	free(before_quotes);
	free(tmp);
	return (joined);
}

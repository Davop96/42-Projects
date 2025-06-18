/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_automata.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:52:04 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:52:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Initialize the DFA
void	ms_automata_init(t_dfa *dfa)
{
	dfa->current_state = STATE_START;
}

// Handles transitions from the start state based on the token type
t_automata	ms_transition_from_start(t_token_type token_type)
{
	if (token_type == TOKEN_WORD)
		return (STATE_WORD);
	if (token_type == TOKEN_HEREDOC)
		return (STATE_HEREDOC);
	if (token_type == TOKEN_REDIRECT_IN)
		return (STATE_REDIRECT_IN);
	if (token_type == TOKEN_REDIRECT_OUT)
		return (STATE_REDIRECT_OUT);
	if (token_type == TOKEN_APPEND)
		return (STATE_APPEND);
	if (token_type == TOKEN_SEMICOLON)
		return (STATE_ERROR);
	return (STATE_ERROR);
}

// Handles transitions from the word state based on the token type
t_automata	ms_transition_from_word(t_token_type token_type)
{
	if (token_type == TOKEN_PIPE)
		return (STATE_PIPE);
	if (token_type == TOKEN_SEMICOLON)
		return (STATE_SEMICOLON);
	if (token_type == TOKEN_REDIRECT_IN)
		return (STATE_REDIRECT_IN);
	if (token_type == TOKEN_REDIRECT_OUT)
		return (STATE_REDIRECT_OUT);
	if (token_type == TOKEN_HEREDOC)
		return (STATE_HEREDOC);
	if (token_type == TOKEN_APPEND)
		return (STATE_APPEND);
	if (token_type == TOKEN_WORD)
		return (STATE_WORD);
	return (STATE_ERROR);
}

// Handles transitions from special states based on the token type
t_automata	ms_transition_from_specials(t_token_type token_type)
{
	if (token_type == TOKEN_WORD)
		return (STATE_WORD);
	if (token_type == TOKEN_HEREDOC)
		return (STATE_HEREDOC);
	if (token_type == TOKEN_REDIRECT_IN)
		return (STATE_REDIRECT_IN);
	if (token_type == TOKEN_REDIRECT_OUT)
		return (STATE_REDIRECT_OUT);
	if (token_type == TOKEN_APPEND)
		return (STATE_APPEND);
	if (token_type == TOKEN_SEMICOLON)
		return (STATE_ERROR);
	return (STATE_ERROR);
}

// Define the DFA transitions using separate functions for each state
t_automata	ms_automata_transition(t_automata state, t_token_type token_type)
{
	t_automata	next_state;

	next_state = STATE_ERROR;
	if (state == STATE_START)
		next_state = ms_transition_from_start(token_type);
	else if (state == STATE_WORD)
		next_state = ms_transition_from_word(token_type);
	else if (state == STATE_PIPE || state == STATE_REDIRECT_IN
		|| state == STATE_REDIRECT_OUT || state == STATE_HEREDOC
		|| state == STATE_APPEND)
		next_state = ms_transition_from_specials(token_type);
	return (next_state);
}

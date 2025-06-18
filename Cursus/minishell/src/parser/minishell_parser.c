/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:52:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:52:35 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Process tokens using the DFA and return the final state
t_automata	ms_process_tokens(t_token *tokens, t_mshell *mshell)
{
	t_dfa		dfa;
	t_token		*current_token;

	ms_automata_init(&dfa);
	current_token = tokens;
	while (current_token)
	{
		dfa.current_state = ms_automata_transition(dfa.current_state,
				current_token->type);
		if (dfa.current_state == STATE_ERROR)
		{
			ms_print_parse_error(current_token->type, mshell);
			return (STATE_ERROR);
		}
		current_token = current_token->next;
	}
	return (dfa.current_state);
}

// Validate the final state and return whether the token sequence is valid
int	ms_validate_final_state(t_automata final_state,
	t_token *prev_token, t_mshell *mshell)
{
	if (final_state == STATE_PIPE || final_state == STATE_REDIRECT_IN
		|| final_state == STATE_REDIRECT_OUT || final_state == STATE_HEREDOC
		|| final_state == STATE_APPEND)
	{
		ms_print_parse_error(prev_token->type, mshell);
		return (0);
	}
	return (final_state != STATE_ERROR);
}

// Process tokens using the DFA and validate the final state
int	ms_automata_monitor(t_token *tokens, t_mshell *mshell)
{
	t_token		*prev_token;
	t_token		*current_token;
	t_automata	final_state;
	int			is_valid;

	prev_token = NULL;
	current_token = tokens;
	while (current_token)
	{
		if (current_token->quote_type == QUOTE_SINGLE)
		{
			final_state = STATE_END;
			return (1);
		}
		prev_token = current_token;
		current_token = current_token->next;
	}
	final_state = ms_process_tokens(tokens, mshell);
	is_valid = ms_validate_final_state(final_state, prev_token, mshell);
	return (is_valid);
}

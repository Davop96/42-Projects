/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_variables_expand_2.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:19 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:21 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Copies the value of an environment variable to the output
char	*ms_copy_to_output(int *j, t_var *env_lst, char *output, char *vr_name)
{
	t_var	*current;
	char	*value;

	current = ms_get_env_var(env_lst, vr_name);
	free(vr_name);
	if (current)
	{
		value = ft_strchr(current->env_var, '=') + 1;
		while (*value)
		{
			output[(*j)++] = *value++;
		}
		return (output);
	}
	return (NULL);
}

// Processes the input $ character and updates the output.
char	*ms_process_char(t_var *env_list, const char *input, char *output,
						t_counters *counters)
{
	if (input[counters->i] == '$')
	{
		if (!ms_process_env_var(env_list, input, output, counters))
			return (NULL);
	}
	else
		output[counters->j++] = input[counters->i++];
	return (output);
}

// Expands environment variables in all tokens except single-quoted ones
void	ms_expand_variables_in_tokens(t_var *env_list, t_token *tokens,
	int exit_status)
{
	t_token	*current;
	char	*expanded_value;

	current = tokens;
	while (current != NULL)
	{
		if (current->quote_type != QUOTE_SINGLE)
		{
			expanded_value = ms_replace_env_vars(env_list,
					current->value, exit_status);
			if (expanded_value)
			{
				free(current->value);
				current->value = expanded_value;
			}
		}
		current = current->next;
	}
}

void	ms_remove_empty_tokens(t_token **tokens)
{
	t_token	*curr;
	t_token	*prev;
	t_token	*to_free;

	curr = *tokens;
	prev = NULL;
	while (curr)
	{
		if (!curr->value || curr->value[0] == '\0')
		{
			to_free = curr;
			if (prev)
				prev->next = curr->next;
			else
				*tokens = curr->next;
			curr = curr->next;
			free(to_free->value);
			free(to_free);
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}
}

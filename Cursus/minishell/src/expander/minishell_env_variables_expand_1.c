/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_variables_expand_1.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:14 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:15 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Extracts the environment variable name from the input string.
char	*ms_extract_var_name(const char *input, int *i)
{
	int		var_len;
	char	*var_name;

	var_len = 0;
	if (!ft_isalpha(input[*i]) && input[*i] != '_')
		return (NULL);
	while (input[*i + var_len] && (ft_isalnum(input[*i + var_len])
			|| input[*i + var_len] == '_'))
		var_len++;
	if (var_len > 0)
	{
		var_name = ms_ft_strndup(input + *i, var_len);
		if (!var_name)
		{
			printf("Error\n");
			return (NULL);
		}
		*i = *i + var_len;
		return (var_name);
	}
	return (NULL);
}

// Searches for and gets the value of an env var in the "name=value" format.
t_var	*ms_get_env_var(t_var *head, const char *name)
{
	t_var	*current;
	int		name_len;

	current = head;
	name_len = ft_strlen(name);
	while (current != NULL)
	{
		if (ft_strncmp(current->env_var, name, name_len) == 0
			&& current->env_var[name_len] == '=')
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}

// Processes and replaces the environment variable in the output string
char	*ms_process_env_var(t_var *env_list, const char *input, char *output,
							t_counters *counters)
{
	int		dollar_count;
	char	*var_name;

	counters->i++;
	dollar_count = ms_count_dollar_signs(input, counters);
	if (dollar_count > 1)
	{
		dollar_count = ms_handle_dollar_pairs(output, counters, dollar_count);
		ms_handle_remaining_dollar(output, counters, dollar_count);
		return (output);
	}
	var_name = ms_extract_var_name(input, &(counters->i));
	if (!var_name || var_name[0] == '\0')
	{
		output[counters->j++] = '$';
		return (output);
	}
	if (!ms_copy_to_output(&(counters->j), env_list, output, var_name))
		return (output);
	return (output);
}

// Handles a $-expansion and updates output and counters
static void	ms_handle_dollar_expansion(t_var *env_list, char *input,
	char *output, t_counters *counters)
{
	if (input[counters->i + 1] == '?')
	{
		ms_expand_exit_status(output, &counters->j, counters->exit_status);
		counters->i += 2;
	}
	else
	{
		if (!ms_process_env_var(env_list, input, output, counters))
			counters->i++;
	}
}

// Processes and replaces environment variables in the input string.
char	*ms_replace_env_vars(t_var *env_list, char *input, int exit_status)
{
	t_counters	counters;
	char		*output;
	size_t		needed_size;

	counters.i = 0;
	counters.j = 0;
	counters.exit_status = exit_status;
	needed_size = ms_calculate_expanded_length(env_list, input, exit_status);
	output = ms_malloc(needed_size);
	while (input[counters.i] != '\0')
	{
		if (input[counters.i] == '$')
		{
			ms_handle_dollar_expansion(env_list, input, output, &counters);
			continue ;
		}
		else
			output[counters.j++] = input[counters.i++];
	}
	output[counters.j] = '\0';
	return (output);
}

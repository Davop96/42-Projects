/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_variables_dollar_2.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:09 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:10 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Expands $?
static int	ms_expand_exit(char *output, t_counters *counters)
{
	char	*status;
	int		k;

	status = ms_itoa(counters->exit_status);
	k = 0;
	while (status[k])
		output[counters->j++] = status[k++];
	free(status);
	counters->i++;
	return (1);
}

// Expands $VAR or $_
static int	ms_expand_env_variable(t_var *env_list, const char *input,
	char *output, t_counters *counters)
{
	char	*var_name;

	var_name = ms_extract_var_name(input, &(counters->i));
	if (!var_name)
		return (0);
	if (!ms_copy_to_output(&(counters->j), env_list, output, var_name))
	{
		free(var_name);
		return (0);
	}
	free(var_name);
	return (1);
}

// Handles literal '$'
static int	ms_expand_literal_dollar(char *output, t_counters *counters)
{
	output[counters->j++] = '$';
	return (1);
}

// Main dispatcher
int	ms_handle_variable_expansion(
	t_var *env_list, const char *input, char *output, t_counters *counters)
{
	int	res;

	if (input[counters->i] == '?')
		res = ms_expand_exit(output, counters);
	else if (ft_isalpha(input[counters->i]) || input[counters->i] == '_')
		res = ms_expand_env_variable(env_list, input, output, counters);
	else
		res = ms_expand_literal_dollar(output, counters);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_variables_length.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:24 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:25 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//Calculates the length needed for $? expansion
static size_t	ms_expanded_exit_status_length(int exit_status)
{
	char		*status_str;
	size_t		len;

	status_str = ms_itoa(exit_status);
	len = ft_strlen(status_str);
	free(status_str);
	return (len);
}

//Calculates the length needed for $VAR expansion
static size_t	ms_expanded_var_length(t_var *env_list, const char *input,
	int var_start, int var_end)
{
	size_t		len;
	char		*var_name;
	t_var		*var;

	len = 0;
	var_name = ms_ft_strndup(input + var_start, var_end - var_start);
	var = ms_get_env_var(env_list, var_name);
	free(var_name);
	if (var)
		len = ft_strlen(ft_strchr(var->env_var, '=') + 1);
	return (len);
}

// Advances i over a variable name and returns the new index
static int	ms_advance_var_name(const char *input, int i)
{
	if (!input[i] || !(ft_isalpha(input[i]) || input[i] == '_'))
		return (i);
	i++;
	while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
		i++;
	return (i);
}

// Handles a $VAR reference and updates len and i
static void	ms_handle_var_reference(
	t_var *env_list, const char *input, size_t *len, int *i)
{
	int		var_start;
	int		var_end;

	if (!input[*i + 1] || !(ft_isalpha(input[*i + 1])
			|| input[*i + 1] == '_'))
	{
		(*len)++;
		(*i)++;
		return ;
	}
	var_start = *i + 1;
	var_end = ms_advance_var_name(input, var_start);
	if (var_end > var_start)
		*len += ms_expanded_var_length(env_list, input, var_start, var_end);
	else
		(*len)++;
	*i = var_end;
}

// Calculates the length of the input string after expanding all env vars
size_t	ms_calculate_expanded_length(t_var *env_list, const char *input,
	int exit_status)
{
	size_t	len;
	int		i;

	len = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '$')
		{
			if (input[i + 1] == '?')
			{
				len += ms_expanded_exit_status_length(exit_status);
				i += 2;
				continue ;
			}
			ms_handle_var_reference(env_list, input, &len, &i);
		}
		else
		{
			len++;
			i++;
		}
	}
	return (len + 1);
}

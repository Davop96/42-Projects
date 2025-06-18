/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins_export_2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:13:25 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:13:27 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Checks if the first character of an env var is valid
int	ms_is_valid_env_var_start(char c)
{
	return (ft_isalpha(c) || c == '_');
}

// Checks if the rest of the env var name is valid
int	ms_is_valid_env_var_body(const char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] != '=')
	{
		if (!(ft_isalnum(str[i]) || str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

// It checks if the environment variable is valid.
int	ms_is_valid_env_var(const char *str)
{
	if (!str || str[0] == '=')
	{
		ms_ft_stderr("bash: export: ");
		ms_ft_stderr((char *)str);
		ms_ft_stderr(": not a valid identifier\n");
		return (0);
	}
	if (!ms_is_valid_env_var_start(str[0]))
	{
		ms_ft_stderr("bash: export: ");
		ms_ft_stderr((char *)str);
		ms_ft_stderr(": not a valid identifier\n");
		return (0);
	}
	if (!ms_is_valid_env_var_body(str))
	{
		ms_ft_stderr("bash: export: ");
		ms_ft_stderr((char *)str);
		ms_ft_stderr(": not a valid identifier\n");
		return (0);
	}
	return (1);
}

// Helper function to find a variable in the list by key
t_var	*ms_find_var(t_var *head, const char *key)
{
	t_var	*current;
	size_t	key_len;

	current = head;
	key_len = ft_strlen(key);
	while (current)
	{
		if (ft_strncmp(current->env_var, key, key_len) == 0
			&& current->env_var[key_len] == '=')
			return (current);
		current = current->next;
	}
	return (NULL);
}

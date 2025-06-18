/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins_unset.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:13:33 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:13:35 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// It checks if the environment variable is valid.
int	ms_is_valid_key(const char *key)
{
	int	i;

	if (!key || key[0] == '\0' || strchr(key, '='))
		return (0);
	if (!(ft_isalpha(key[0]) || key[0] == '_'))
		return (0);
	i = 1;
	while (key[i] != '\0')
	{
		if (!(ft_isalnum(key[i]) || key[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

// Helper: Checks if the current variable matches the key
static int	ms_var_matches_key(const char *env_var,
	const char *key, size_t key_len)
{
	if (ft_strncmp(env_var, key, key_len) != 0)
		return (0);
	if (env_var[key_len] == '=' || env_var[key_len] == '\0')
		return (1);
	return (0);
}

// Remove a variable from the list by key
void	ms_remove_var(t_var **head, const char *key)
{
	t_var	*current;
	t_var	*prev;
	size_t	key_len;

	if (!head || !*head || !key)
		return ;
	current = *head;
	prev = NULL;
	key_len = ft_strlen(key);
	while (current)
	{
		if (ms_var_matches_key(current->env_var, key, key_len))
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->env_var);
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

// Implementation of the unset builtin
void	ms_builtin_unset(t_mshell *mshell, t_var **head, char **args)
{
	int	i;
	int	error;

	error = 0;
	if (!args[1])
		return ;
	i = 1;
	while (args[i])
	{
		if (ms_is_valid_key(args[i]))
			ms_remove_var(head, args[i]);
		else
		{
			ms_ft_stderr("bash: unset: ");
			ms_ft_stderr(args[i]);
			ms_ft_stderr(": not a valid identifier\n");
			error = 1;
		}
		i++;
	}
	mshell->exit_status = error;
}

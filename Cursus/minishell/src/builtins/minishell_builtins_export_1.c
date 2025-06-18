/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins_export_1.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:13:18 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:13:19 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// If the variable doesn't exist, it adds it.
int	ms_add_new_var(t_var **head, const char *env_var)
{
	t_var	*new_node;
	t_var	*current;

	new_node = ms_create_node_and_dup_var(env_var);
	if (!new_node)
		return (0);
	if (*head == NULL)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (1);
}

// If the variable exists, it updates its value.
int	ms_update_existing_var(t_var *existing_var, const char *env_var)
{
	if (!existing_var)
		return (0);
	free(existing_var->env_var);
	existing_var->env_var = ft_strdup(env_var);
	if (!existing_var->env_var)
		return (0);
	return (1);
}

// Add or update an environment variable in the list
void	ms_add_or_update_var(t_var **head, const char *env_var)
{
	char	*key;
	char	*eq;
	t_var	*existing_var;

	key = ft_strdup(env_var);
	if (!key)
		return ;
	eq = ft_strchr(key, '=');
	if (eq)
		*eq = '\0';
	existing_var = ms_find_var(*head, key);
	if (existing_var)
	{
		if (!ms_update_existing_var(existing_var, env_var))
			printf("Error: Failed to update variable.\n");
	}
	else
	{
		if (!ms_add_new_var(head, env_var))
			printf("Error: Failed to add new variable.\n");
	}
	free(key);
}

// Print the environment variables as they are stored in the list
void	ms_print_env(t_var *head)
{
	t_var	*current;

	current = head;
	while (current)
	{
		printf("declare -x %s\n", current->env_var);
		current = current->next;
	}
}

// Implementation of the export builtin
void	ms_builtin_export(t_mshell *mshell, t_var **head, char **args)
{
	int		i;
	int		error;

	error = 0;
	if (!args[1])
	{
		ms_print_env(*head);
		return ;
	}
	i = 1;
	while (args[i])
	{
		if (!ms_is_valid_env_var(args[i]))
			error = 1;
		else
			ms_add_or_update_var(head, args[i]);
		i++;
	}
	if (error)
		mshell->exit_status = 1;
	else
		mshell->exit_status = 0;
}

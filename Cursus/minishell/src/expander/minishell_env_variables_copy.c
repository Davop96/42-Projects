/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_variables_copy.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:13:57 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:13:58 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Create a new node and copy the environment variable.
t_var	*ms_create_node_and_dup_var(const char *env_var)
{
	t_var	*new_node;

	new_node = (t_var *)ms_malloc(sizeof(t_var));
	if (new_node == NULL)
	{
		printf("Error.\n");
		return (NULL);
	}
	new_node->env_var = ft_strdup(env_var);
	if (new_node->env_var == NULL)
	{
		printf("Error.\n");
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

// Free memory from the list.
void	ms_free_list(t_var *head)
{
	t_var	*current;
	t_var	*next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current->env_var);
		free(current);
		current = next_node;
	}
}

// Prints the list of environment variables.
void	ms_print_list(t_var *head)
{
	t_var	*current;

	current = head;
	while (current != NULL)
	{
		printf("%s\n", current->env_var);
		current = current->next;
	}
}

// Creates the list, iterates through and copies the environment variables.
t_var	*ms_dup_env_var(char **envp)
{
	t_var	*head;
	t_var	*current;
	t_var	*new_node;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (envp[i] != NULL)
	{
		new_node = ms_create_node_and_dup_var(envp[i]);
		if (new_node == NULL)
		{
			ms_free_list(head);
			return (NULL);
		}
		if (head == NULL)
			head = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	return (head);
}

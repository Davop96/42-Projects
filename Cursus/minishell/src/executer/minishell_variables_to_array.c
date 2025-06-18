/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_variables_to_array.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:55:48 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:55:50 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Counts the number of environment variables in the list
int	ms_count_env_vars(t_var *head)
{
	int		count;
	t_var	*current;

	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

// Fills the array with environment variables from the list
char	**ms_fill_env_array(t_var *head, int count)
{
	char	**env;
	t_var	*current;
	int		i;

	env = (char **)ms_malloc((count + 1) * sizeof(char *));
	if (!env)
		return (NULL);
	current = head;
	i = 0;
	while (current)
	{
		env[i] = ft_strdup(current->env_var);
		if (!env[i])
		{
			ms_free_env_array(env);
			return (NULL);
		}
		i++;
		current = current->next;
	}
	env[i] = NULL;
	return (env);
}

// Converts the environment variable list to an array
char	**ms_env_list_to_array(t_mshell *mshell)
{
	int		count;

	count = ms_count_env_vars(mshell->env_list);
	return (ms_fill_env_array(mshell->env_list, count));
}

// Sets or updates an environment variable in the env_list.
void	ms_set_env_var(t_var **env_list, const char *new_var)
{
	t_var		*var;
	size_t		name_len;
	t_var		*new;

	var = *env_list;
	name_len = 0;
	while (new_var[name_len] && new_var[name_len] != '=')
		name_len++;
	while (var)
	{
		if (ft_strncmp(var->env_var, new_var, name_len)
			== 0 && var->env_var[name_len] == '=')
		{
			free(var->env_var);
			var->env_var = ft_strdup(new_var);
			return ;
		}
		var = var->next;
	}
	new = ms_malloc(sizeof(t_var));
	new->env_var = ft_strdup(new_var);
	new->next = *env_list;
	*env_list = new;
}

// Frees the memory allocated for the environment variable array
void	ms_free_env_array(char **env)
{
	int	i;

	if (!env)
		return ;
	i = 0;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:54:43 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:54:46 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Splits the PATH variable into directories
char	**ms_split_path_directories(t_var *env_list)
{
	t_var	*path_var;
	char	**paths;

	path_var = ms_get_env_var(env_list, "PATH");
	if (!path_var)
		return (NULL);
	paths = ft_split(path_var->env_var + 5, ':');
	return (paths);
}

// Searches for the executable in the given directories
char	*ms_find_executable_in_paths(char **paths, char *command)
{
	char	*full_path;
	int		i;

	if (!command || !*command)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = ft_strjoin(paths[i], "/");
		full_path = ms_strjoin_free(full_path, command);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}

// Searches for the executable in the PATH directories
char	*ms_find_executable(char *command, t_var *env_list)
{
	char	**paths;
	char	*executable;

	if (!command || !*command)
		return (NULL);
	if (ft_strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (ft_strdup(command));
		return (NULL);
	}
	paths = ms_split_path_directories(env_list);
	if (!paths)
		return (NULL);
	executable = ms_find_executable_in_paths(paths, command);
	ms_free_split(paths);
	return (executable);
}

// Extracts the command path and arguments from tokens
void	ms_path_and_args(t_mshell *mshell, t_token *cmd_token)
{
	int		arg_index;
	t_token	*token;

	arg_index = 0;
	token = cmd_token;
	while (token && (!token->value || token->value[0] == '\0'
			|| token->type != TOKEN_WORD))
		token = token->next;
	if (token && token->value)
		mshell->command.path = ft_strdup(token->value);
	else
		mshell->command.path = NULL;
	token = cmd_token;
	while (token != NULL && token->type == TOKEN_WORD)
	{
		if (token->value && token->value[0] != '\0')
			mshell->command.args[arg_index++] = ft_strdup(token->value);
		token = token->next;
	}
	mshell->command.args[arg_index] = NULL;
}

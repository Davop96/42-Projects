/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins_cd_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:12:55 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:12:57 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Changes the directory to the user's home directory
int	ms_cd_to_home(t_var *env_list)
{
	const char	*home;
	t_var		*home_var;

	home_var = ms_get_env_var(env_list, "HOME");
	if (home_var == NULL)
	{
		ms_ft_stderr("cd: HOME not set\n");
		return (1);
	}
	home = home_var->env_var + 5;
	if (chdir(home) != 0)
	{
		ms_ft_stderr("cd: ");
		ms_ft_stderr((char *)home);
		ms_ft_stderr(": ");
		ms_ft_stderr(strerror(errno));
		ms_ft_stderr("\n");
		return (1);
	}
	return (0);
}

// Changes the directory to the specified path
int	ms_cd_to_path(const char *path)
{
	if (chdir(path) != 0)
	{
		ms_ft_stderr("cd: ");
		ms_ft_stderr((char *)path);
		ms_ft_stderr(": No such file or directory\n");
		return (1);
	}
	return (0);
}

// Updates the PWD environment variable
void	ms_update_pwd(t_var **env_list)
{
	char	cwd[1024];
	char	*pwd_str;

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		pwd_str = ft_strjoin("PWD=", cwd);
		ms_add_or_update_var(env_list, pwd_str);
		free(pwd_str);
	}
	else
		perror("cd");
}

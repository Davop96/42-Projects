/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:26:57 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/11/28 16:28:31 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*check_command(char *command, char *envp)
{
	char	*str;
	char	**split;
	int		x;

	x = 0;
	str = ft_substr(envp, 5, ft_strlen(envp));
	split = ft_split(str, ':');
	free(str);
	while (split[x] != NULL)
	{
		str = ft_strjoin(split[x], command);
		if (access(str, F_OK | X_OK) == 0)
			break ;
		free(str);
		str = NULL;
		x++;
	}
	while (split[x] != NULL)
		x++;
	free_split(split, x);
	return (str);
}

void	check_files(t_args *args)
{
	if (access(args->file1, F_OK) != 0)
	{
		ft_printf("Infile not found\n");
		free_args(args);
		exit(1);
	}
	if (access(args->file1, R_OK) != 0)
	{
		ft_printf("Infile permissions denied\n");
		free_args(args);
		exit(5);
	}
}

t_args	check_args(t_args *args, char **envp)
{
	int	x;

	x = 0;
	check_files(args);
	while (ft_strncmp(envp[x], "PATH=", 5) != 0)
		x++;
	args->cmd1_path = check_command(args->cmd1, envp[x]);
	if (args->cmd1_path == NULL)
	{
		ft_printf("Command not found\n");
		free_args(args);
		exit(127);
	}
	args->cmd2_path = check_command(args->cmd2, envp[x]);
	if (args->cmd2_path == NULL)
	{
		ft_printf("Command not found\n");
		free_args(args);
		exit(127);
	}
	return (*args);
}

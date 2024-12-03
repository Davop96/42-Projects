/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checker_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:48:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/12/02 12:27:07 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	init_args(t_args *args, char **argv, int argc)
{
	int		x;
	t_cmd	*temp_cmd;
	t_list	*temp;
	t_list	*first;

	x = 1;
	temp = NULL;
	first = NULL;
	init_all_valgrind(args);
	args->file1 = argv[x++];
	while (x < argc - 1)
	{
		temp_cmd = ft_new_command(argv[x++]);
		ft_add_cmd_back(&args->command, temp_cmd);
		temp = ft_lstnew(ft_strjoin("/", temp_cmd->cmd[0]));
		if (!first)
			first = temp;
		ft_lstadd_back(&args->cmd, temp);
		args->cmd_nbr++;
	}
	args->file2 = argv[x];
	args->cmd = first;
}

char	*check_command(char *command, char *envp)
{
	char	*str;
	char	**split;
	int		x;

	str = ft_substr(envp, 5, ft_strlen(envp));
	split = ft_split(str, ':');
	free(str);
	x = 0;
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

void	aux_error_args(t_args *args, t_list *temp)
{
	if (args->heredoc_flag == 1)
		unlink(".heredoc_tmp");
	free(temp);
	ft_printf("Command not found\n");
	free_args(args);
	exit(127);
}

t_args	check_args(t_args *args, char **envp)
{
	t_list	*temp;
	t_list	*first;
	int		x;

	temp = args->cmd_path;
	first = args->cmd;
	x = 0;
	while (ft_strncmp(envp[x], "PATH=", 5) != 0)
		x++;
	check_files(args);
	while (first)
	{
		temp = ft_lstnew(check_command(first->content, envp[x]));
		if (temp->content == NULL)
			aux_error_args(args, temp);
		ft_lstadd_back(&args->cmd_path, temp);
		first = first->next;
	}
	return (*args);
}

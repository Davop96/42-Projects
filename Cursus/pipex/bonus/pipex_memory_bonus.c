/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_memory_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:47:28 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/12/02 12:28:23 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	manage_error(t_args *args, char *error)
{
	perror(error);
	free_args(args);
	exit(EXIT_FAILURE);
}

void	*free_split(char **str, int cont)
{
	int	x;

	x = 0;
	while (x < cont)
	{
		free(str[x]);
		x++;
	}
	free(str);
	return (NULL);
}

void	ft_list_clear(t_list **args)
{
	t_list	*temp;

	if (!args)
		return ;
	while (*args)
	{
		temp = (*args)->next;
		free((*args)->content);
		free(*args);
		*args = temp;
	}
	*args = NULL;
}

void	free_path(t_args *args)
{
	t_list	*temp_path;

	temp_path = args->cmd_path;
	while (args->cmd_path)
	{
		free(args->cmd_path->content);
		args->cmd_path = args->cmd_path->next;
	}
	args->cmd_path = temp_path;
	ft_list_clear(&args->cmd_path);
}

void	*free_args(t_args *args)
{
	int		x;
	t_cmd	*temp;

	ft_list_clear(&args->cmd);
	if (args->cmd_path)
		ft_list_clear(&args->cmd_path);
	while (args->command)
	{
		x = 0;
		while (args->command->cmd[x])
			x++;
		free_split(args->command->cmd, x);
		temp = args->command->next;
		free(args->command);
		args->command = temp;
	}
	free(args);
	return (NULL);
}

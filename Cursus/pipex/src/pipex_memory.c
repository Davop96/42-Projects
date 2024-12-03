/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:28:51 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/11/28 16:30:45 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	manage_errors(t_args *args, char *error)
{
	perror(error);
	free_args(args);
	exit(EXIT_FAILURE);
}

void	*free_split(char **str, int count)
{
	int	x;

	x = 0;
	while (x < count)
	{
		free(str[x]);
		x++;
	}
	free(str);
	return (NULL);
}

void	free_command(t_args *args)
{
	int	x;

	x = 0;
	if (args->command1 != NULL)
	{
		while (args->command1[x])
			x++;
		free_split(args->command1, x);
	}
	x = 0;
	if (args->command2 != NULL)
	{
		while (args->command2[x])
			x++;
		free_split(args->command2, x);
	}
}

void	*free_args(t_args *args)
{
	if (args->cmd1 != NULL)
		free(args->cmd1);
	if (args->cmd2 != NULL)
		free(args->cmd2);
	if (args->cmd1_path != NULL)
		free(args->cmd1_path);
	if (args->cmd2_path != NULL)
		free(args->cmd2_path);
	free_command(args);
	if (args != NULL)
		free(args);
	return (NULL);
}

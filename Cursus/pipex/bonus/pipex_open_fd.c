/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_open_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:59:22 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/11/28 17:00:23 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void	open_infile(t_args *args)
{
	args->fd1 = open(args->file1, O_RDONLY);
	if (args->fd1 < 0)
		manage_error(args, "open");
}

void	open_outfile_heredoc(t_args *args)
{
	if (access(args->file2, F_OK) != 0)
	{
		args->fd2 = open(args->file2, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (args->fd2 < 0)
			manage_error(args, "open");
	}
	else
	{
		args->fd2 = open(args->file2, O_WRONLY | O_APPEND, 0644);
		if (args->fd2 < 0)
			manage_error(args, "open");
	}
}

void	open_outfile(t_args *args)
{
	if (ft_strcmp(args->file1, ".heredoc_tmp") != 0)
	{
		if (access(args->file2, F_OK) != 0)
		{
			args->fd2 = open(args->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (args->fd2 < 0)
				manage_error(args, "open");
		}
		else
		{
			args->fd2 = open(args->file2, O_WRONLY | O_TRUNC, 0644);
			if (args->fd2 < 0)
				manage_error(args, "open");
		}
	}
	else
		open_outfile_heredoc(args);
}

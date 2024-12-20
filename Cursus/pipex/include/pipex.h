/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:26:09 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/12/02 11:30:18 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_args
{
	char	*cmd1;
	char	*cmd2;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**command1;
	char	**command2;
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
}	t_args;

// Check arguments

char	*check_command(char *command, char *envp);
void	check_files(t_args *args);
t_args	check_args(t_args *args, char **envp);

// Free memory

void	manage_errors(t_args *args, char *error);
void	*free_split(char **str, int count);
void	free_command(t_args *args);
void	*free_args(t_args *args);

// Utils

void	init_valgrind(t_args *args);
void	init_args(t_args *args, char **argv);
void	open_infile(t_args *args);
void	open_outfile(t_args *args);
void	child_process_cmd(t_args *args, int pipefd[2], char **envp);

#endif
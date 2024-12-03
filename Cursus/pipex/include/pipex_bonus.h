/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:24:38 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/12/02 16:16:16 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

typedef struct s_cmd
{
	char			**cmd;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_args
{
	t_list	*cmd;
	t_list	*cmd_path;
	t_cmd	*command;
	t_list	*first_cmd;
	t_list	*first_path;
	t_cmd	*first_command;
	char	*limiter;
	char	*file1;
	char	*file2;
	int		fd1;
	int		fd2;
	int		cmd_nbr;
	int		index;
	int		heredoc_flag;
}	t_args;

// Check arguments

void	init_args(t_args *args, char **argv, int argc);
char	*check_command(char *command, char *envp);
void	check_files(t_args *args);
void	aux_error_args(t_args *args, t_list *temp);
t_args	check_args(t_args *args, char **envp);

// Free memory

void	manage_error(t_args *args, char *error);
void	*free_split(char **str, int cont);
void	ft_list_clear(t_list **args);
void	free_path(t_args *args);
void	*free_args(t_args *args);

// Here doc func

void	init_all_valgrind(t_args *args);
void	init_here_doc(t_args *args, char **argv, int argc);
void	here_doc_pipex(t_args *args, char **argv, int argc);

// Open fd

void	open_infile(t_args *args);
void	open_outfile_heredoc(t_args *args);
void	open_outfile(t_args *args);

// Utils

void	manage_child(t_args *args, char **envp);
void	child_process_cmd(t_args *args, int pipefd[2], char **envp);
void	ft_add_cmd_back(t_cmd **lst, t_cmd *new);
t_cmd	*ft_new_command(char *content);
int		ft_strcmp(const char *s1, const char *s2);

#endif
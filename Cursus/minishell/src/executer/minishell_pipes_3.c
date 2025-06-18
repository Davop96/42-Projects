/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipes_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:55:11 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:55:13 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

//Free argv array
static void	ms_free_argv(char **argv)
{
	int	k;

	k = 0;
	if (!argv)
		return ;
	while (argv[k])
	{
		free(argv[k]);
		k++;
	}
	free(argv);
}

// Helper: Handle redirections and exit if failed
static void	ms_child_handle_redirections(t_mshell *mshell, char **argv,
	t_token *cmd_start, t_token *end)
{
	ms_handle_redirections(mshell, cmd_start, end);
	if (mshell->red_fail)
	{
		ms_free_argv(argv);
		exit(1);
	}
}

// Helper: Handle builtin execution and exit if executed
static void	ms_child_handle_builtin(char **argv, t_mshell *mshell)
{
	if (ms_builtin_main(argv, -1, mshell, &mshell->env_list))
	{
		ms_free_argv(argv);
		exit(mshell->exit_status);
	}
}

//Handle execve logic and cleanup
static void	ms_child_execve(char *prepared_path, char **argv, t_mshell *mshell)
{
	char	**env;

	env = ms_prepare_env_array(mshell);
	if (!env)
	{
		free(prepared_path);
		ms_free_argv(argv);
		exit(127);
	}
	ms_handle_child_process(prepared_path, argv, -1, env);
	ms_free_env_array(env);
	ms_free_argv(argv);
	free(prepared_path);
	exit(127);
}

// Main child logic, now divided
void	ms_execute_pipeline_child(t_pipe *ctx)
{
	char	**argv;
	char	*prepared_path;

	ms_setup_child_fds(ctx->i, ctx->num_pipes, ctx->pipes);
	argv = ms_build_argv_for_pipe(ctx->cmd_start);
	ms_child_handle_redirections(ctx->mshell, argv, ctx->cmd_start, ctx->end);
	ms_child_handle_builtin(argv, ctx->mshell);
	prepared_path = ms_find_executable(argv[0], ctx->mshell->env_list);
	if (!prepared_path)
	{
		ms_print_command_not_found(argv[0], ctx->mshell);
		ms_free_argv(argv);
		exit(127);
	}
	ms_child_execve(prepared_path, argv, ctx->mshell);
}

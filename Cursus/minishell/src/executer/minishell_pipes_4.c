/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_pipes_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:55:18 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:55:20 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Finds the end of the current segment (before the next pipe)
t_token	*ms_find_segment_end(t_token *start)
{
	t_token	*end;

	end = start;
	while (end && end->type != TOKEN_PIPE)
		end = end->next;
	return (end);
}

// Helper: Handles one pipeline segment and updates the segment pointer
static void	ms_pipeline_segment_loop(t_pipe *ctx)
{
	t_token	*cmd_start;
	t_token	*end;
	t_token	*restore;

	cmd_start = ctx->segment;
	end = ms_find_segment_end(cmd_start);
	restore = NULL;
	if (end)
	{
		restore = end->next;
		end->next = NULL;
	}
	ctx->cmd_start = cmd_start;
	ctx->end = end;
	ctx->pids[ctx->i] = fork();
	if (ctx->pids[ctx->i] == 0)
		ms_execute_pipeline_child(ctx);
	if (end)
		end->next = restore;
	ctx->segment = restore;
}

// Main pipeline execution function
void	ms_execute_pipeline(t_mshell *mshell)
{
	t_pipe	ctx;

	ctx.num_pipes = ms_count_pipes(mshell->tokens);
	ctx.num_cmds = ctx.num_pipes + 1;
	ctx.pipes = ms_create_pipes(ctx.num_pipes);
	ctx.pids = ms_malloc(sizeof(pid_t) * ctx.num_cmds);
	ctx.segment = mshell->tokens;
	ctx.mshell = mshell;
	ctx.i = 0;
	while (ctx.i < ctx.num_cmds)
	{
		ms_pipeline_segment_loop(&ctx);
		ctx.i++;
	}
	ms_close_all_pipes(ctx.pipes, ctx.num_pipes);
	ms_wait_for_children(ctx.pids, ctx.num_cmds, mshell);
	free(ctx.pids);
}

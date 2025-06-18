/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:53:40 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:53:43 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Initializes the minishell structure with default values and env variables.
void	ms_init_main(t_mshell *mshell, char **env)
{
	mshell->env_list = ms_dup_env_var(env);
	mshell->tokens = NULL;
	mshell->parser = NULL;
	mshell->exit_status = 0;
	mshell->command.heredoc_fd = -1;
	mshell->command.saved_stdin = dup(STDIN_FILENO);
	mshell->command.args[0] = NULL;
	mshell->command.path = NULL;
	ms_signals_main(mshell);
}

// Tracks the shell nesting level.
void	ms_level(t_var **env_list)
{
	t_var	*level_var;
	int		level;
	char	*level_num;
	char	level_str[32];

	level_var = ms_get_env_var(*env_list, "MS_LEVEL");
	if (!level_var)
		return ;
	level = ft_atoi(level_var->env_var + 9);
	level++;
	level_num = ms_itoa(level);
	ms_strcpy(level_str, "MS_LEVEL=");
	ms_strcpy(level_str + 9, level_num);
	ms_set_env_var(env_list, level_str);
	free(level_num);
}

// Frees resources allocated in the minishell structure.
void	ms_free_main(t_mshell *mshell)
{
	ms_free_list(mshell->env_list);
	if (mshell->tokens)
		ms_free_tokens(mshell->tokens);
	if (mshell->parser)
		free(mshell->parser);
	ms_free_command_args(&mshell->command);
	if (mshell->command.path)
		free(mshell->command.path);
	if (mshell->command.saved_stdin != -1)
		close(mshell->command.saved_stdin);
}

// Handles the main loop of the shell.
void	ms_main_loop(t_mshell *mshell)
{
	char	*input;

	while (1)
	{
		input = readline("minishell > ");
		if (input == NULL)
			ms_handle_eof(mshell);
		if (*input)
		{
			add_history(input);
			mshell->tokens = ms_tokenize(input);
			if (ms_automata_monitor(mshell->tokens, mshell))
			{
				ms_execute_command(mshell);
				ms_free_command_args(&mshell->command);
				free(mshell->command.path);
				mshell->command.path = NULL;
			}
			ms_free_tokens(mshell->tokens);
			mshell->tokens = NULL;
		}
		free(input);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_mshell	mshell;

	(void)argc;
	(void)argv;
	ms_init_main(&mshell, env);
	ms_level(&mshell.env_list);
	ms_main_loop(&mshell);
	rl_clear_history();
	ms_free_main(&mshell);
	return (0);
}

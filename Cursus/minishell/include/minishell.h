/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:56:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:56:08 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h> 
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"

# define BOLD_TEXT "\033[1m"
# define RESET_TEXT "\033[0m"

//#define malloc(size) 0

//Tokens
typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_HEREDOC,
	TOKEN_APPEND,
	TOKEN_SEMICOLON,
	TOKEN_UNKNOWN
}	t_token_type;

// Define quote types
typedef enum e_quote_type
{
	QUOTE_NONE,
	QUOTE_SINGLE,
	QUOTE_DOUBLE
}	t_quote_type;

// Updated token structure to include quote type

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	t_quote_type	quote_type;
	struct s_token	*next;
}	t_token;

//Parser list
typedef struct s_parse
{
	t_token		*tokens;
	char		*start;
	char		*end;
}	t_parse;

typedef enum e_automata
{
	STATE_START,
	STATE_WORD,
	STATE_PIPE,
	STATE_REDIRECT_IN,
	STATE_REDIRECT_OUT,
	STATE_HEREDOC,
	STATE_APPEND,
	STATE_SEMICOLON,
	STATE_ERROR,
	STATE_END
}	t_automata;

//Structures
typedef struct s_dfa
{
	t_automata	current_state;
}	t_dfa;

typedef struct t_var
{
	char			*env_var;
	struct t_var	*next;
}	t_var;

typedef struct t_counters
{
	int	i;
	int	j;
	int	exit_status;
}	t_counters;

typedef struct s_command
{
	char	*path;
	char	*args[256];
	int		fd_out;
	int		saved_stdin;
	int		heredoc_fd;
}	t_command;

struct	s_mshell;

typedef struct s_pipe
{
	int				i;
	int				num_pipes;
	int				num_cmds;
	int				**pipes;
	pid_t			*pids;
	t_token			*segment;
	t_token			*cmd_start;
	t_token			*end;
	struct s_mshell	*mshell;
}	t_pipe;

typedef struct s_mshell
{
	t_var		*env_list;
	t_token		*tokens;
	t_parse		*parser;
	t_dfa		automata;
	t_command	command;
	t_counters	counters;
	int			exit_status;
	int			red_fail;
	int			heredoc_interrupted;
}	t_mshell;

//Tokenizer

t_token			*ms_create_token(char *value, t_token_type type,
					t_quote_type quote_type);
void			ms_add_token(t_token **tokens, char *value,
					t_token_type type, t_quote_type quote_type);
t_token_type	ms_get_token_type(char *token);
char			*ms_handle_quotes(char **end,
					t_quote_type *quote_type, char **start);
void			ms_handle_spaces(char **start, char **end,
					t_token **tokens);
void			ms_handle_special_chars(char **start, char **end,
					t_token **tokens);
int				ms_count_unescaped_quotes(const char *input);
char			*ms_handle_text_before_quotes(char **start, char **end);
char			*ms_prompt_for_additional_input(char *input);
char			*ms_handle_incompletes(char *input);
void			ms_add_final_token(char **start, char **end,
					t_token **tokens);
void			ms_process_token(char **start, char **end,
					t_token **tokens);
t_token			*ms_tokenize(char *input);
char			*ms_remove_escapes(const char *input);
void			ms_free_tokens(t_token *tokens);
int				ms_is_valid_env_char(char c);
char			*ms_free_quotes(char *before_quotes,
					char *result, char *final_result);
char			*ms_collect_token(char **input, t_quote_type *quote_type);
int				ms_has_unclosed_quote(const char *input);

//Parser

void			ms_automata_init(t_dfa *dfa);
t_automata		ms_transition_from_start(t_token_type token_type);
t_automata		ms_transition_from_word(t_token_type token_type);
t_automata		ms_transition_from_specials(t_token_type token_type);
t_automata		ms_automata_transition(t_automata state,
					t_token_type token_type);
t_automata		ms_process_tokens(t_token *tokens, t_mshell *mshell);
int				ms_validate_final_state(t_automata final_state,
					t_token *prev_token, t_mshell *mshell);
int				ms_automata_monitor(t_token *tokens, t_mshell *mshell);

//Errors

void			ms_print_parse_error(t_token_type token_type,
					t_mshell *mshell);
void			ms_print_command_not_found(const char *command,
					t_mshell *mshell);
int				ms_print_special_errors(char *input, t_mshell *mshell);
void			ms_update_exit_status_on_signal(int sig, t_mshell *mshell);

//Builtins

void			ms_builtin_echo(char **args);
int				ms_echo_n_flag(char **args, int *index);
void			ms_builtin_pwd(void);
void			ms_builtin_env(t_var *head);
void			ms_builtin_exit(t_mshell *mshell);
int				ms_cd_to_home(t_var *env_list);
int				ms_cd_to_path(const char *path);
void			ms_update_pwd(t_var **env_list);
void			ms_builtin_cd(char **args, t_var *env_list, t_mshell *mshell);
int				ms_builtin_main(char **args, int fd_out,
					t_mshell *mshell, t_var **head);
t_var			*ms_find_var(t_var *head, const char *key);
int				ms_add_new_var(t_var **head, const char *env_var);
int				ms_update_existing_var(t_var *existing_var,
					const char *env_var);
void			ms_add_or_update_var(t_var **head, const char *env_var);
void			ms_print_env(t_var *head);
void			ms_builtin_export(t_mshell *mshell, t_var **head, char **args);
void			ms_remove_var(t_var **head, const char *key);
void			ms_builtin_unset(t_mshell *mshell, t_var **head, char **args);
int				ms_read_builtins(char **args, t_mshell *mshell, t_var **head);
int				ms_is_valid_env_var(const char *str);

//Executer

int				ms_check_command(t_mshell *mshell);
void			ms_free_command_args(t_command *command);
void			ms_level(t_var **env_list);
void			ms_set_env_var(t_var **env_list, const char *new_var);
void			ms_handle_command(t_mshell *mshell);
void			ms_path_and_args(t_mshell *mshell, t_token *cmd_token);
char			**ms_prepare_env_array(t_mshell *mshell);
void			ms_handle_child_process(char *path, char **args,
					int fd_out, char **env);
void			ms_handle_parent_process(pid_t pid, t_mshell *mshell);
void			ms_fork(t_mshell *mshell);
int				ms_execute_special_cases(t_mshell *mshell,
					t_token *command_start);
void			ms_execute_command_logic(t_mshell *mshell);
void			ms_check_execution(t_mshell *mshell,
					t_token *command_start, t_token *current_token);
void			ms_handle_pipeline_or_command(t_mshell *mshell,
					t_token **command_start,
					t_token **current_token);				
void			ms_execute_command(t_mshell *mshell);
int				ms_count_env_vars(t_var *head);
char			**ms_fill_env_array(t_var *head, int count);
char			**ms_env_list_to_array(t_mshell *mshell);
void			ms_free_env_array(char **env);
char			**ms_split_path_directories(t_var *env_list);
char			*ms_find_executable_in_paths(char **paths, char *command);
char			*ms_find_executable(char *command, t_var *env_list);
char			*ms_prepare_executable(t_mshell *mshell);
void			ms_execute_pipeline(t_mshell *mshell);
int				ms_count_pipes(t_token *tokens);
void			ms_free_main(t_mshell *mshell);

//Redirections

int				ms_create_pipe(int pipefd[2]);
void			ms_read_heredoc_input(int write_fd,
					t_token *delimiter_token, t_mshell *mshell);
void			ms_handle_heredoc(t_token *token, int *heredoc_fd,
					t_mshell *mshell);
void			ms_handle_heredoc_tokens(t_mshell *mshell,
					t_token *current_token);
int				ms_handle_cat_with_heredoc(t_mshell *mshell,
					t_token *command_start);
int				ms_perror_input(const char *message, int fd_in);
int				ms_handle_output_redirection(t_token *cmd_token,
					int *fd_out, t_mshell *mshell);
int				ms_handle_input_redirection(t_token *cmd_token,
					int *saved_stdin);
int				ms_process_output_redirection(t_token *cmd_token,
					t_mshell *mshell);
int				ms_process_input_redirection(t_token *cmd_token,
					int *saved_stdin, t_mshell *mshell);
int				ms_process_redirection_token(t_token *cmd_token,
					t_mshell *mshell, int *saved_stdin);
void			ms_handle_redirections(t_mshell *mshell,
					t_token *command_start, t_token *current_token);
void			ms_restore_stdin(int *saved_stdin);
void			ms_restore_stdout(int saved_stdout);
char			**ms_build_argv_for_redirection(t_token *segment);

//Pipes

int				ms_count_pipes(t_token *tokens);
int				**ms_create_pipes(int num_pipes);
void			ms_close_all_pipes(int **pipes, int num_pipes);
void			ms_setup_child_fds(int i, int num_pipes, int **pipes);
void			ms_wait_for_children(pid_t *pids, int num_cmds,
					t_mshell *mshell);
t_token			*ms_find_segment_end(t_token *start);
void			ms_execute_pipeline_child(t_pipe *ctx);
char			**ms_build_argv_for_pipe(t_token *pipe);

//Expander

t_var			*ms_create_node_and_dup_var(const char *env_var);
void			ms_free_list(t_var *head);
void			ms_print_list(t_var *head);
t_var			*ms_dup_env_var(char **envp);
char			*ms_extract_var_name(const char *input, int *i);
t_var			*ms_get_env_var(t_var *head, const char *name);
char			*ms_copy_to_output(int *j, t_var *env_lst,
					char *output, char *vr_name);
char			*ms_process_env_var(t_var *env_list, const char *input,
					char *output, t_counters *counters);
char			*ms_process_char(t_var *env_list, const char *input,
					char *output, t_counters *counters);
char			*ms_replace_env_vars(t_var *env_list,
					char *input, int exit_status);
void			ms_expand_variables_in_tokens(t_var *env_list,
					t_token *tokens, int exit_status);
int				ms_count_dollar_signs(const char *input, t_counters *counters);
int				ms_handle_dollar_pairs(char *output,
					t_counters *counters, int dollar_count);
void			ms_handle_remaining_dollar(char *output,
					t_counters *counters, int dollar_count);
int				ms_count_dollars(const char *value);
int				ms_handle_two_dollars(t_mshell *mshell);
int				ms_handle_dollar_count(const char *value, t_mshell *mshell);
int				ms_handle_more_than_two_dollars(int dollar_count,
					char *pid_str, t_mshell *mshell);
int				ms_handle_odd_dollars(int dollar_count,
					char *pid_str, t_mshell *mshell);
int				ms_handle_even_dollars(int dollar_count,
					char *pid_str, t_mshell *mshell);
int				ms_handle_variable_expansion(t_var *env_list, const char *input,
					char *output, t_counters *counters);
size_t			ms_calculate_expanded_length(t_var *env_list,
					const char *input, int exit_status);
void			ms_exit_status(char *input, t_mshell *mshell);
int				ms_expand_exit_status(char *output, int *j, int exit_status);
void			ms_remove_empty_tokens(t_token **tokens);

//Signals

void			ms_handle_sigint(int sig, t_mshell *mshell);
void			ms_handle_sigquit(int sig);
void			ms_handle_eof(t_mshell *mshell);
void			ms_handle_sigint_wrapper(int sig);
void			ms_signals_main(t_mshell *mshell);
void			ms_heredoc_sigint_handler(int sig);

//Utils

int				ms_ft_strcmp(const char *s1, const char *s2);
char			*ms_ft_strndup(const char *s1, size_t n);
int				ms_ft_is_space(char c);
void			ms_ft_stderr(const char *message);
void			*ms_malloc(size_t size);
int				ms_ft_str_is_space(const char *str);
int				ms_ft_str_is_n(const char *str);
void			ms_reverse_string(char *str, int len);
int				ms_int_to_buffer(int n, char *buffer);
char			*ms_itoa(int n);
char			*ms_strcpy(char *dest, const char *src);
char			*ms_strjoin_free(char *s1, const char *s2);
pid_t			ms_getpid(void);
void			ms_free_split(char **split);

#endif
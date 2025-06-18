/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtins_echo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:13:09 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:13:11 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Handles the echo builtin command
void	ms_builtin_echo(char **args)
{
	int		i;
	int		no_newline;

	i = 1;
	no_newline = ms_echo_n_flag(args, &i);
	while (args[i] != NULL)
	{
		printf("%s", args[i]);
		if (args[i + 1] != NULL)
			printf(" ");
		i++;
	}
	if (!no_newline)
		printf("\n");
}

// Handles the -n flag for the echo command
int	ms_echo_n_flag(char **args, int *index)
{
	int	no_newline;

	no_newline = 0;
	while (args[*index] != NULL && args[*index][0]
			== '-' && ms_ft_str_is_n(args[*index] + 1))
	{
		no_newline = 1;
		(*index)++;
	}
	return (no_newline);
}

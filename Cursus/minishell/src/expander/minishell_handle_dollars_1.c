/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_handle_dollars_1.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:33 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:34 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Counts the number of consecutive '$' characters
int	ms_count_dollars(const char *value)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (value[i] == '$')
	{
		count++;
		i++;
	}
	return (count);
}

// Handles the special case of exactly two '$'
int	ms_handle_two_dollars(t_mshell *mshell)
{
	char	*pid_str;

	pid_str = ms_itoa(ms_getpid());
	if (!pid_str)
		return (1);
	ms_print_command_not_found(pid_str, mshell);
	free(pid_str);
	return (1);
}

// Handles the logic for counting '$' and special cases like $$ or $$$
int	ms_handle_dollar_count(const char *value, t_mshell *mshell)
{
	int		dollar_count;
	char	*pid_str;

	dollar_count = ms_count_dollars(value);
	if (dollar_count > 2)
	{
		pid_str = ms_itoa(ms_getpid());
		if (!pid_str)
			return (1);
		ms_handle_more_than_two_dollars(dollar_count, pid_str, mshell);
		free(pid_str);
		return (1);
	}
	if (dollar_count == 2 && value[2] == '\0')
		return (ms_handle_two_dollars(mshell));
	return (0);
}

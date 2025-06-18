/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_env_variables_dollar_1.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:03 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:04 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Counts consecutive '$' characters in the input
int	ms_count_dollar_signs(const char *input, t_counters *counters)
{
	int		dollar_count;

	dollar_count = 1;
	while (input[counters->i] == '$')
	{
		dollar_count++;
		counters->i++;
	}
	return (dollar_count);
}

// Handles pairs of '$' by replacing them with the PID
int	ms_handle_dollar_pairs(char *output, t_counters *counters, int dollar_count)
{
	char	*pid_str;
	int		k;

	while (dollar_count >= 2)
	{
		pid_str = ms_itoa(ms_getpid());
		if (!pid_str)
			return (0);
		k = 0;
		while (pid_str[k] != '\0')
		{
			output[counters->j++] = pid_str[k];
			k++;
		}
		free(pid_str);
		dollar_count -= 2;
	}
	return (dollar_count);
}

// Handles any remaining single '$'
void	ms_handle_remaining_dollar(char *output, t_counters *counters,
	int dollar_count)
{
	if (dollar_count == 1)
		output[counters->j++] = '$';
}

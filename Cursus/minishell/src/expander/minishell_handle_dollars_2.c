/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_handle_dollars_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:38 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:39 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Handles odd numbers of '$'
int	ms_handle_odd_dollars(int dollar_count, char *pid_str, t_mshell *mshell)
{
	char	*output;
	int		j;

	output = ms_malloc(ft_strlen(pid_str) + (dollar_count / 2) + 1);
	if (!output)
		return (1);
	ms_strcpy(output, pid_str);
	j = 0;
	while (j < dollar_count / 2)
	{
		output[ft_strlen(pid_str) + j] = '$';
		j++;
	}
	output[ft_strlen(pid_str) + j] = '\0';
	ms_print_command_not_found(output, mshell);
	free(output);
	return (0);
}

// Handles even numbers of '$'
int	ms_handle_even_dollars(int dollar_count, char *pid_str, t_mshell *mshell)
{
	char	*output;
	int		j;
	int		len;

	len = ft_strlen(pid_str) * (dollar_count / 2);
	output = ms_malloc(len + 1);
	if (!output)
		return (1);
	output[0] = '\0';
	j = 0;
	while (j < dollar_count / 2)
	{
		ms_strcpy(output + (j * ft_strlen(pid_str)), pid_str);
		j++;
	}
	output[len] = '\0';
	ms_print_command_not_found(output, mshell);
	free(output);
	return (0);
}

// Handles cases with more than two '$'
int	ms_handle_more_than_two_dollars(int dollar_count,
	char *pid_str, t_mshell *mshell)
{
	int	result;

	if (dollar_count % 2 == 1)
		result = ms_handle_odd_dollars(dollar_count, pid_str, mshell);
	else
		result = ms_handle_even_dollars(dollar_count, pid_str, mshell);
	return (result);
}

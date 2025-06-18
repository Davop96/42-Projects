/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exit_status.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvacas-h <dvacas-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 15:14:29 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/06/12 15:14:30 by dvacas-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Prints the shell's last exit status if the input is exactly "$?"
void	ms_exit_status(char *input, t_mshell *mshell)
{
	if (input != NULL && ms_ft_strcmp(input, "$?") == 0)
		printf("%d\n", mshell->exit_status);
}

// Writes the exit status as a string into output at position *j
int	ms_expand_exit_status(char *output, int *j, int exit_status)
{
	char	*status_str;
	int		k;

	status_str = ms_itoa(exit_status);
	k = 0;
	while (status_str[k])
		output[(*j)++] = status_str[k++];
	free(status_str);
	return (k);
}

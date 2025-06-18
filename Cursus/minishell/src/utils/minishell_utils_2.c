/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:50:34 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:50:38 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Checks if the given string contains only whitespace characters
int	ms_ft_str_is_space(const char *str)
{
	while (*str)
	{
		if (!ms_ft_is_space(*str))
			return (0);
		str++;
	}
	return (1);
}

// Checks if the given string contains only the character 'n'
int	ms_ft_str_is_n(const char *str)
{
	while (*str)
	{
		if (*str != 'n')
			return (0);
		str++;
	}
	return (1);
}

// Reverses a string in place
void	ms_reverse_string(char *str, int len)
{
	int		i;
	char	temp;

	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

// Converts an integer to a reversed character buffer
int	ms_int_to_buffer(int n, char *buffer)
{
	int		i;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	i = 0;
	if (n == 0)
	{
		buffer[i++] = '0';
	}
	while (n != 0)
	{
		if (n < 0)
			buffer[i++] = '0' - (n % 10);
		else
			buffer[i++] = '0' + (n % 10);
		n /= 10;
	}
	if (is_negative)
		buffer[i++] = '-';
	buffer[i] = '\0';
	return (i);
}

// Converts an integer to a string
char	*ms_itoa(int n)
{
	char	buffer[12];
	int		len;
	char	*result;
	int		i;

	len = ms_int_to_buffer(n, buffer);
	ms_reverse_string(buffer, len);
	result = ms_malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = buffer[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

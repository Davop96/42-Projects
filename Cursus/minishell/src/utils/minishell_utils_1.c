/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:50:21 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:50:26 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* Compares two strings and returns the difference between
the first differing characters. */
int	ms_ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

// Duplicates up to n characters from the given string.
char	*ms_ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	i;

	copy = (char *)ms_malloc((n + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < n && s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

// Checks if the given character is a whitespace character.
int	ms_ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

// Writes an error message to standard error
void	ms_ft_stderr(const char *message)
{
	write(2, message, ft_strlen(message));
}

// Allocates memory and exits the program if allocation fails
void	*ms_malloc(size_t t_size)
{
	void	*ptr;

	(void) t_size;
	ptr = malloc(t_size);
	if (!ptr)
	{
		ms_ft_stderr("Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

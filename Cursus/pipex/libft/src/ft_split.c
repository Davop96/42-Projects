/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:02:18 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/12 16:29:24 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*get_next_word(const char *str, char c, int *index)
{
	int		start;
	int		end;
	char	*word;

	while (str[*index] && str[*index] == c)
		(*index)++;
	start = *index;
	while (str[*index] && str[*index] != c)
		(*index)++;
	end = *index;
	word = ft_substr(str, start, end - start);
	return (word);
}

static void	free_split(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		word_count;
	int		i;
	int		index;

	if (!str)
		return (NULL);
	word_count = count_words(str, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	index = 0;
	while (i < word_count)
	{
		result[i] = get_next_word(str, c, &index);
		if (!result[i])
		{
			free_split(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

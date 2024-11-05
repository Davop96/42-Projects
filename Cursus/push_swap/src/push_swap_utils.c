/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:02:59 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/11/04 12:51:44 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		x;
	int		sign;
	long	res;

	x = 0;
	sign = 1;
	res = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == 43 || str[x] == 45)
	{
		if (str[x] == 45)
			sign = -sign;
		x++;
	}
	while (str[x] >= 48 && str[x] <= 57)
	{
		res = (str[x] - 48) + 10 * res;
		x++;
	}
	res = res * sign;
	return (res);
}

char	**fill_split(char **split, char const *s, char c)
{
	size_t	x;
	int		y;
	size_t	z;

	x = 0;
	z = 0;
	y = -1;
	while (x <= (size_t)ft_strlen(s))
	{
		if (s[x] != c && y == -1)
			y = x;
		else if ((s[x] == c || x == (size_t)ft_strlen(s)) && y != -1)
		{
			split[z] = ft_substr(s, y, x - y);
			if (!split[z])
				if (free_split(split, z) == NULL)
					return (NULL);
			z++;
			y = -1;
		}
		x++;
	}
	split[z] = NULL;
	return (split);
}

unsigned int	malloc_size(char const *s, char c)
{
	int	ms;
	int	x;

	x = 0;
	ms = 0;
	if (s[0] == c)
		x++;
	while (s[x] != '\0')
	{
		if (s[x] == c && s[x - 1] != c)
			ms++;
		x++;
	}
	if (s[x - 1] != c)
		ms++;
	return (ms);
}

void	*free_split(char **split, int z)
{
	while (z >= 0)
	{
		free(split[z]);
		z--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = (char **)malloc((malloc_size(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = fill_split(split, s, c);
	if (!split)
		return (free_split(split, malloc_size(s, c)));
	return (split);
}

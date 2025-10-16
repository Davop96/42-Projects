/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:49:05 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/03 16:09:45 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	x;

	len = 0;
	while (s1[len])
		len++;
	dup = (char *)malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	x = 0;
	while (x < len)
	{
		dup[x] = s1[x];
		x++;
	}
	dup [x] = '\0';
	return (dup);
}

int	ft_strlen(const char *c)
{
	int	x;

	x = 0;
	while (c[x] != '\0')
		x++;
	return (x);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		return (ft_strdup(""));
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	i = 0;
	while (i < s1_len)
		joined_str[i++] = *s1++;
	while (*s2)
		joined_str[i++] = *s2++;
	joined_str[i] = '\0';
	return (joined_str);
}

void	fill_str(char *res, char *s1, char *s2)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	y = 0;
	while (s1[y])
		res[x++] = s1[y++];
	y = 0;
	while (s2[y])
		res[x++] = s2[y++];
	res[x] = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:56:14 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 16:23:14 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (NULL);
	}
	return ((char *)s);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
	{
		len_s2++;
		
	}
	if (!(str = malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	i = -1;
	while (++i < len_s1)
		str[i] = s1[i];
	j = 0;
	while (j < len_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

static char *ft_strdup(const char *s)
{
    char *copy;
    int i;

    i = 0;
    while (s[i])
        i++;
    if (!(copy = malloc(i + 1)))
        return (NULL);
    i = -1;
    while (s[++i])
        copy[i] = s[i];
    copy[i] = '\0';
    return (copy);
}

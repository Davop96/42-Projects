/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:50:46 by dbohoyo-          #+#    #+#             */
/*   Updated: 2025/06/05 10:50:49 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// Copies a null-terminated string from src to dest
char	*ms_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// Combines two strings and frees the first string
char	*ms_strjoin_free(char *s1, const char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)ms_malloc(len1 + len2 + 1);
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	ms_strcpy(result, s1);
	ms_strcpy(result + len1, s2);
	free(s1);
	return (result);
}

// Retrieves the process ID by reading from /proc/self/stat
pid_t	ms_getpid(void)
{
	int		fd;
	char	buffer[256];
	int		i;
	pid_t	pid;

	fd = open("/proc/self/stat", O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (-1);
	}
	if (read(fd, buffer, sizeof(buffer) - 1) == -1)
	{
		perror("read");
		close(fd);
		return (-1);
	}
	buffer[255] = '\0';
	close(fd);
	i = 0;
	while (buffer[i] >= '0' && buffer[i] <= '9')
		i++;
	buffer[i] = '\0';
	pid = (pid_t)ft_atoi(buffer);
	return (pid);
}

// Frees a null-terminated array of strings
void	ms_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

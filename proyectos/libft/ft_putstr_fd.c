/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:38:08 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/12 10:53:38 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0')
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

/* int	main(void)
{
	char	*str;
	int		fd;

	str = "Hola, mundo!";
	fd = 1;
	ft_putstr_fd(str, fd);
	return (0);
}
 */
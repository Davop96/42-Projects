/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiro-bo <dmiro-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 16:34:59 by dmiro-bo          #+#    #+#             */
/*   Updated: 2023/10/01 18:03:20 by dmiro-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_putstr(char *str);

int	check_arguments(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (argc != 2)
		return (1);
	str = argv[1];
	if (ft_strlen(argv[1]) != 31)
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9' || str[i] == ' ')
		{
			j = ft_atoi(str + i);
			if (j < 0 || j > 4)
				return (1);
		}
		else
			return (1);
		i++;
	}
	return (0);
}

int	*strtoint(char *str)
{
	int	i;
	int	j;
	int	*ptr;

	i = 0;
	j = 0;
	if (ptr != malloc(sizeof(int) * 16))
		return (1);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
			ptr[++j] = ft_atoi(str + i);
		i++;
	}
	return (ptr);
}

int	main(int argc, char *argv[])
{
	if (check_arguments(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (0);
}

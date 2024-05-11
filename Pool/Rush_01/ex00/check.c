/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiro-bo <dmiro-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:12:21 by dmiro-bo          #+#    #+#             */
/*   Updated: 2023/10/01 18:05:49 by dmiro-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi(char *str);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);

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
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
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
	if (!(ptr = malloc(sizeof(int) * 16)))
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] >= 48 && str[i] <= 57)
		{
			ptr[j] = ft_atoi(str + i);
			j++;
		}
		i++;
	}
	return (ptr);
}

void	print_puzzle_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(grid[i][j]);
			if (j < 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

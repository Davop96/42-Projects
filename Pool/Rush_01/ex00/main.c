/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmiro-bo <dmiro-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:51:34 by mgama             #+#    #+#             */
/*   Updated: 2023/10/01 18:06:53 by dmiro-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_cell(int grid[4][4], int gap, int pattern[16]);
void	ft_putstr(char *str);
int		*strtoint(char *str);
void	print_puzzle_grid(int grid[4][4]);
int		check_arguments(int argc, char *argv[]);

int	check_adjacent_cell(int grid[4][4], int gap, int num)
{
	int	i;

	i = 0;
	while (i < gap / 4)
	{
		if (grid[i][gap % 4] == num)
			return (1);
		i++;
	}
	i = 0;
	while (i < gap % 4)
	{
		if (grid[gap / 4][i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	puzzle_solver(int grid[4][4], int pattern[16], int gap)
{
	int	num;

	if (gap == 16)
		return (1);
	num = 0;
	while (++num <= 4)
	{
		if (check_adjacent_cell(grid, gap, num) == 0)
		{
			grid[gap / 4][gap % 4] = num;
			if (check_cell(grid, gap, pattern) == 0)
			{
				if (puzzle_solver(grid, pattern, gap + 1) == 1)
					return (1);
			}
			else
			{
				grid[gap / 4][gap % 4] = 0;
			}
		}
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	int grid[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
	};
	int *pattern;

	if (check_arguments(argc, argv) == 1)
	{
		ft_putstr("Error\n");
		return (0);
	}
	pattern = strtoint(argv[1]);
	if (!pattern)
		return (1);
	if (puzzle_solver(grid, pattern, 0) == 1)
	{
		print_puzzle_grid(grid);
	}/* 
	else
	{
		ft_putstr("Error\n");
	} */
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:42:50 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:49:45 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		ft_putchar(str[x]);
		x++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc >= 1)
	{
		ft_putstr(argv[0]);
	}
	ft_putchar('\n');
	return (0);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:54:26 by dvacas-h          #+#    #+#             */
/*   Updated: 2025/10/09 14:46:14 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

// Check if number of arguments is correct.
int	cb_check_number_args(int argc)
{
	if (argc != 2)
	{
		printf("Error: invalid number of arguments.\n");
		return (1);
	}
	return (0);
}

// Check if file's extension is correct.
int	cb_check_extension(char *argv)
{
	char	*str;
	int		i;
	int		j;

	str = ".cub";
	i = ft_strlen(argv);
	j = ft_strlen(str);
	while (j >= 0)
	{
		if (argv[i] != str[j])
		{
			printf("Error: invalid argument format.\n");
			return (1);
		}
		i--;
		j--;
	}
	return (0);
}

int	cb_parse_main(int argc, char **argv)
{
	if (cb_check_number_args(argc) == 1)
		return (1);
	if (cb_check_extension(argv[1]) == 1)
		return (1);
	if (cb_check_identifiers_count(argv[1]) == 1)
		return (1);
	if (cb_check_map_empty_lines(argv[1]) == 1)
		return (1);
	if (cb_check_map_allowed_chars(argv[1]) == 1)
		return (1);
	return (0);
}

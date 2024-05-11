/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:38:21 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/09/25 17:03:27 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str [count])
	{
		write(1, &str[count], 1);
		count ++;
	}
}

/*int	main(void)
{
	char	*str;

	str = "Hola amigo";
	ft_putstr(str);
}
*/
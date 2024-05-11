/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 09:13:43 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/09/21 15:13:38 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	int	negativo;
	int	positivo;

	positivo = 'P';
	negativo = 'N';
	if (n >= 0)
	{
		write(1, &positivo, 1);
	}
	else
	{
		write(1, &negativo, 1);
	}
}

/*int	main(void)
{
	ft_is_negative(-2);
	return (0);
}
*/
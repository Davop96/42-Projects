/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:37:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/11 15:12:17 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *b, size_t n)
{
	char	*x;

	x = (char *)b;
	while (n > 0)
	{
		*x = 0;
		x++;
		n--;
	}
	return (b);
}

/* int	main(void)
{
	char str[60] = "Mariano Rajoy, el del viva el vino.";

	ft_bzero(str + 0, 13);
	printf("M.Rajoy es en realidad el señor %s\n", str);
	return (0);
}
 */
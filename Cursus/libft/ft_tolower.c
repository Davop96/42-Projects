/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:39:55 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/09 16:47:28 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/* int	main(void)
{
	char	c;
	char	result;

	c = 'D';
	result = ft_tolower(c);
	printf("El resultado es %c\n", result);

	c = 'd';
	result = ft_tolower(c);
	printf("El resultado es %c\n", result);

}
 */
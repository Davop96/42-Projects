/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:10:08 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/09 16:40:42 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

/* int	main(void)
{
	char	c;
	char	result;

	c = 'D';
	result = ft_toupper(c);
	printf("El resultado es %c\n", result);

	c = 'd';
	result = ft_toupper(c);
	printf("El resultado es %c\n", result);

} */

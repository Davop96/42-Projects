/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:28:06 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:47:34 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	else if (index < 2)
	{
		return (index);
	}
	return (ft_fibonacci(index - 1) + (ft_fibonacci(index - 2)));
}

/* int	main(void)
{
	int	index;

	index = 8;
	printf("%d\n", ft_fibonacci(index));
	return (0);
}
 */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 11:35:50 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/11 09:47:27 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	number_d(int div)
{
	int temp;

	if (div >= 100)
	{
		printf("%d\n", (div / 100));
		printf("%d\n", 100);
	}
	temp = div - ((div / 100) * 100);
	if (temp >= 20)
	{
		if (((temp / 10) * 10) != 0)
		{
			printf("%d\n", ((temp / 10) * 10));
		}
		if ((temp - ((temp / 10) * 10)) != 0)
		{
			printf("%d\n", (temp - ((temp / 10) * 10)));
		}
	}
	else if (temp != 0)
	{
		printf("%d\n", temp);
	}
}

int main(void)
{
	number_d(949);
	return (0);
}





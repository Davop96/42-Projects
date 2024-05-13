/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 10:33:59 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 12:22:32 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putchar(char x)
{
	write (1, &x, 1);
}

char	divide(char x, unsigned int n)
{
	char	res;

	res = 0;
	if (n == 0)
		res = x / 10 + '0';
	else
		res = x % 10 + '0';
	return (res);
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			putchar(divide(a, 0));
			putchar(divide(a, 1));
			putchar(' ');
			putchar(divide(b, 0));
			putchar(divide(b, 1));
			if (!(a == 98 && b == 99))
				write (1, ", ", 2);
			b++;
		}
		a++;
	}
}

/*int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/
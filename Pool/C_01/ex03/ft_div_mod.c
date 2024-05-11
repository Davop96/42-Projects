/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 15:24:02 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/09/23 17:24:00 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*int	main(void)
{
	int	a;
	int	b;
	int	rdiv;
	int	rmod;
	int	*div = &rdiv;
	int	*mod = &rmod;

	a = 18;
	b = 4;
	ft_div_mod(a, b, div, mod);
	printf("Cociente es: %d\n", *div);
	printf("Resto es: %d\n", *mod);
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:51:40 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/05/13 14:32:14 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	x;

	if (n == 0)
	{
		return (0);
	}
	x = 0;
	while (s1[x] == s2[x] && s1[x] && s2[x] && x < n)
	{
		x++;
	}
	if (x == n)
	{
		x--;
	}
	return (s1[x] - s2[x]);
}

/*int	main(void)
{
	char	*s1;
	char	*s2;
	unsigned int	n;

	s1 = "this";
	s2 = "thix";
	n = 10;
	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}
*/
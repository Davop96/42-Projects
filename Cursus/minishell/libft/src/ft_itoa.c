/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:11:32 by dbohoyo-          #+#    #+#             */
/*   Updated: 2024/04/11 16:46:02 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0 && ++len)
		n /= 10;
	return (len);
}

char	*ft_itoa(int num)
{
	char	*dst;
	int		count;
	long	n;

	n = num;
	count = get_num_len(n);
	dst = (char *)malloc((count + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	dst[count--] = '\0';
	if (n == 0)
		dst[0] = '0';
	if (n < 0)
	{
		dst[0] = '-';
		n *= -1;
	}
	while (n != 0)
	{
		dst[count--] = '0' + (n % 10);
		n /= 10;
	}
	return (dst);
}

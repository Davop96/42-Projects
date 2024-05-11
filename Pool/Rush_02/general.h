/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbohoyo- <dbohoyo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:06:16 by dbohoyo-          #+#    #+#             */
/*   Updated: 2023/10/08 15:56:24 by dbohoyo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERAL_H
#define GENERAL_H


int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	r;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
	{
		i = 2;
		r = nb;
		while (i <= power)
		{
			r = r * nb;
			i++;
		}
		return (r);
	}
}
int contador(unsigned int pos, int nb)
{
    int result1;
    int result2;
    
    //Comprueba que sea multiplo de 3
    while ((pos-1) % 3 != 0)
        pos--;
	//Saca los numeros que estan delante y los que quiero los pone a cero
    result1 = (nb / ft_iterative_power(10, (pos + 2))) * ft_iterative_power(10, 3);
    //printf("\n%d\n",result1);

	//Quita los numero que estan atras de los que quiero
    result2 = nb / ft_iterative_power(10, (pos -1));
    //printf("%d", result2);
	//La resta me da los numeros que deseo
    return (result2 - result1);
}

int	ft_atoi(const char *str)
{
	int	res;

	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return res;
}

char	*ft_strdup(char *src)
{
	int		x;
	int		len;
	char		*dest;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	x = 0;
	while (x < len)
	{
		dest[x] = src[x];
		x++;
	}
	dest[x] = '\0';
	return (dest);
}

int	ft_str_is_numeric(char *str)
{
	int	x;
	int	id;

	x = 0;
	id = 1;
	while (str[x] != '\0')
	{
		if (!(str[x] >= '0' && str[x] <= '9'))
		{
			id = 0;
			break ;
		}
		x++;
	}	
	return (id);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	x;

	while (*str)
	{
		if (*str == *to_find)
		{
			x = 0;
			while (to_find[x] && str[x] == to_find[x])
			{
				x++;
			}
			if (to_find[x] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int x;

	x = 0;
	while (str[x])
	{
		write(1, &str[x], 1);
		x++;
	}
}
#endif
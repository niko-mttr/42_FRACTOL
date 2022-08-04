/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:55:08 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/31 16:52:42 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_putnbr(long n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	n = n % 10 + '0';
	return (n);
}

int	ft_size(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_fill(char *str, int size, int minus, long n)
{
	str[size] = 0;
	size--;
	while (size != -1)
	{
		str[size] = ft_putnbr(n);
		n /= 10;
		size--;
		if (!size && minus)
			break ;
	}
	if (minus)
		str[size] = '-';
	return (str);
}

char	*ft_itoa(long n)
{
	char	*str;
	int		size;
	int		minus;
	long	nb;

	nb = n;
	minus = 0;
	size = ft_size(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		minus = -1;
		nb *= -1;
	}
	str = ft_fill(str, size, minus, nb);
	return (str);
}

/*
int	main()
{
	printf("%s", ft_itoa(-20601));
}
*/
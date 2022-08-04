/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:51:37 by nmattera          #+#    #+#             */
/*   Updated: 2022/06/30 12:31:07 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_fillbase(char *tab, unsigned long nb, char *str, int size)
{
	int	sign;

	sign = 0;
	str[size] = 0;
	size--;
	while (size > -1)
	{
		if (size == 0 && sign == 1)
			break ;
		str[size] = tab[nb % 16];
		nb /= 16;
		size--;
	}
}

int	ft_len(unsigned long nb)
{
	int	count;

	count = 1;
	while (nb > 15)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

char	*ft_baseconvert(char *tab, unsigned long n)
{
	unsigned long	nb;
	int				size;
	int				minus;
	char			*str;

	nb = n;
	minus = 0;
	size = ft_len(nb) + minus;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	ft_fillbase(tab, nb, str, size);
	return (str);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int c;
// 	char *s;
// 	s = ft_baseconvert("0123456789abcdef", 127);
// 	printf("%s", s);
// 	free (s);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:17:35 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/16 10:30:26 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main ()
{
	char str[] = "bimbam";
	printf("%p\n", ft_memchr(str, 'i', 10));
	printf("%p", memchr(str, 'i', 10));
}
*/
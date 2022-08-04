/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:00:18 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/16 18:48:35 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (src[y] != '\0')
		y++;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (y);
}

/*
#include <stdio.h>

int	main()
{
	char src [] = "coucou";
	char dest[] = "AAAAAAAAAA";

	printf("%ld\n", ft_strlcpy(dest, src, 0));
	printf("%s", dest);
}
*/
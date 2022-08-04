/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:56:30 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/16 10:30:53 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*nsrc;
	char		*ndest;

	nsrc = (char *)src;
	ndest = (char *)dest;
	if (dest > src)
	{
		while (n)
		{
			ndest[n - 1] = nsrc[n - 1];
			n--;
		}
	}
	else
	{
		i = -1;
		while (++i < n)
			ndest[i] = nsrc[i];
	}
	return (dest);
}

/*
#include<string.h>
#include<stdio.h>

int main()
{
   char csrc[100] = "Geeksfor";
   ft_memmove(csrc+5, csrc, strlen(csrc)+1);
   printf("%s", csrc);
   return 0;
}*/
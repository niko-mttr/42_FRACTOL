/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:09:15 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/16 18:17:35 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char		ch;
	size_t				count;

	count = 0;
	ch = (unsigned char) c;
	while (*s)
	{
		s++;
		count++;
	}
	while ((unsigned char) *s != ch && count)
	{
		s--;
		count--;
	}
	if ((unsigned char) *s == ch)
		return ((char *) s);
	else
		return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int main()
{
	char src[] = "tripouille";
	printf("%s", ft_strrchr(src, 'z'));
}
*/
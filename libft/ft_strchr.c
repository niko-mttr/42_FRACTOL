/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:58:18 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/21 10:27:14 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		ch;

	ch = (unsigned char) c;
	while (*s && (unsigned char)*s != ch)
		++s;
	if (ch == (unsigned char)*s)
		return ((char *) s);
	else
		return (NULL);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char src[] = "cocoricorico";
	printf("%s", ft_strchr(src, 'r'));
} */

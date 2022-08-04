/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:02:59 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/18 10:37:51 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	if (start >= (ft_strlen(s)))
		len = 0;
	else if (len > ft_strlen (s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (len)
	{
		new[i] = s[start];
		start++;
		i++;
		len--;
	}
	new[i] = '\0';
	return (new);
}

/*
#include <stdio.h>

int main()
{
	printf(" la nouvelle : %s", ft_substr("cocoricobim", 6, 2));
}*/

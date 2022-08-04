/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:41:37 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/16 20:17:20 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	count;
	char	*bigi;
	char	*litte;

	bigi = (char *) big;
	litte = (char *) little;
	if (!ft_strlen(litte))
		return (bigi);
	count = 0;
	while (*bigi)
	{
		i = 0;
		while (litte[i] == bigi[i] && litte[i])
			i++;
		if ((i + count) > len)
			return (NULL);
		if (i == ft_strlen(litte) && len >= ft_strlen(litte))
			return (bigi);
		bigi++;
		count++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	char * empty = (char*)"";

	//printf("OG   : %s", source("bimcocoricobim", "cocorico", 12));
	printf("pure : %s", ft_strnstr(haystack, "aaabc", 5));
}
*/
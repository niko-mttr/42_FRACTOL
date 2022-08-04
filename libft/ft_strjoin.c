/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:31:24 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/17 16:42:27 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdlib.h>

/*size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

char	*ft_cat(char *new, char const *src, size_t index)
{
	int		i;

	i = 0;
	while (src[i])
	{
		new[index] = src[i];
		index++;
		i++;
	}
	new[index] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*new;
	size_t		i;

	new = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	ft_cat(new, s2, i);
	return (new);
}

/*
#include <stdio.h>

int	main()
{
	char *new = ft_strjoin("blabla", "bimbam");
	printf("%s", new);
	free(new);
}
*/
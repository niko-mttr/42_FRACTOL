/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:25:22 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/16 17:33:39 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}*/

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;

	new = malloc ((sizeof (char)) * (ft_strlen(s) + 1));
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*
#include <stdio.h>

int	main()
{
	char	*test = ft_strdup("blabla");
	printf("%s", test);
	free (test);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:57:09 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/20 09:57:19 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check(char s, char const *set)
{
	int	i;

	i = -1;
	while (set[++i])
		if (set[i] == s)
			return (1);
	return (0);
}

int	ft_rtrim(char const *str, char const *set)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && check(str[i], set))
	{
		i--;
		count++;
	}
	if (i < 0)
		return (0);
	return (count);
}

int	ft_trim(char const *str, char const *set)
{
	size_t	i;

	i = 0;
	while (str[i] && check(str[i], set))
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	int			count;
	char		*dest;

	count = ft_trim(s1, set) + ft_rtrim(s1, set);
	dest = malloc(sizeof(char) * (ft_strlen(s1) - count + 1));
	i = 0;
	while (i < (ft_strlen(s1) - count))
	{
		dest[i] = s1[ft_trim(s1, set) + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

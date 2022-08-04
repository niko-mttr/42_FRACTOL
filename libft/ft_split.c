/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:03:33 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/25 17:17:26 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_word(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

int	ft_letter(char const *s, char c, int word)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!word)
			break ;
		word--;
		while (s[i] != c && s[i])
			i++;
	}
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

int	ft_pos(char const *s, char c, int word)
{
	int	i;

	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (!word)
			return (i);
		word--;
		while (s[i] != c && s[i])
			i++;
	}
	return (i);
}

char	*ft_fillsplit(char const *s, char c, int word)
{
	int		count;
	int		pos;
	int		i;
	char	*str;

	count = ft_letter(s, c, word);
	str = malloc(sizeof(char) * (count + 1));
	if (!ft_word(s, c))
		return (NULL);
	if (!str)
		return (NULL);
	pos = ft_pos(s, c, word);
	i = 0;
	while (count > 0)
	{	
		str[i] = s[pos + i];
		count--;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;

	tab = malloc((ft_word(s, c) + 1) * sizeof(char *));
	if (!s || !tab)
		return (0);
	i = 0;
	while (i < ft_word(s, c))
	{
		tab[i] = ft_fillsplit(s, c, i);
		i++;
	}
	tab[i] = 0;
	return (tab);
}

/* #include <stdio.h>

int main()
{
	char	**tab;
	char	*test = NULL;

	tab = ft_split("!!!!!!", '!');

	printf("%s\n%s", tab[0], test);
	free(tab);
}
 */
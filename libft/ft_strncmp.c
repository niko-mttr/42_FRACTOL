/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 09:29:53 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/17 17:53:07 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	if (n == 0)
		return (0);
	while (*s1 && *s1 == *s2 && n - 1)
	{	
		s1++;
		s2++;
		n--;
	}
	i = (*s1 - *s2);
	if (*s1 < 0 || *s2 < 0)
		i = (*s2 - *s1);
	return (i);
}

/* 
#include <stdio.h>
#include <string.h>

int main()
{
	printf("la mienne : %d\n", ft_strncmp("test\200", "test\0", 6));
	printf("la vraie : %d", strncmp("test\200", "test\0", 6));
}
 */
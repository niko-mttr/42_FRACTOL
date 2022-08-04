/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:25:49 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/06/30 12:31:20 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexa(unsigned int n, char c)
{
	char	*s;
	int		size;

	if (c == 'x')
		s = ft_baseconvert("0123456789abcdef", n);
	else
		s = ft_baseconvert("0123456789ABCDEF", n);
	ft_putstr_fd(s, 1);
	size = ft_strlen(s);
	free(s);
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 16:45:37 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/06/30 12:31:55 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_pointer(unsigned long ptr)
{
	char	*s;
	int		size;

	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	s = ft_baseconvert("0123456789abcdef", ptr);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(s, 1);
	size = 2 + (int)ft_strlen(s);
	free(s);
	return (size);
}

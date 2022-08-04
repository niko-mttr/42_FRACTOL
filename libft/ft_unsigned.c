/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:22:11 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/06/30 12:32:40 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_unsigned(unsigned int n)
{
	char	*s;
	int		size;

	s = ft_itoa(n);
	ft_putstr_fd(s, 1);
	size = ft_strlen(s);
	free(s);
	return (size);
}

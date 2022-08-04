/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:14:25 by nicolasmatt       #+#    #+#             */
/*   Updated: 2022/06/30 12:32:01 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_number(int n)
{
	char	*s;
	int		size;

	s = ft_itoa(n);
	ft_putstr_fd(s, 1);
	size = (int)ft_strlen(s);
	free(s);
	return (size);
}

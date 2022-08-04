/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolasmattera <nicolasmattera@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:05:54 by nmattera          #+#    #+#             */
/*   Updated: 2022/06/30 13:14:53 by nicolasmatt      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	ft_parsing(const char *c, va_list ap, int *count, int i)
{
	while (c[i])
	{
		if (c[i] == '%')
		{
			if (c[i + 1] == 'c')
				*count += (ft_character(va_arg(ap, int)));
			else if (c[i + 1] == 's')
				*count += (ft_string(va_arg(ap, char *)));
			else if (c[i + 1] == 'p')
				*count += (ft_pointer(va_arg(ap, unsigned long)));
			else if (c[i + 1] == 'i' || c[i + 1] == 'd')
				*count += (ft_number(va_arg(ap, int)));
			else if (c[i + 1] == 'u')
				*count += (ft_unsigned(va_arg(ap, unsigned int)));
			else if (c[i + 1] == 'x' || c[i + 1] == 'X')
				*count += (ft_hexa(va_arg(ap, unsigned int), c[i + 1]));
			else if (c[i + 1] == '%')
				*count += (ft_character('%'));
			i++;
		}
		else
			*count += ft_printchar(c[i]);
		if (c[i])
			i++;
	}
}

int	ft_printf(const char *form, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, form);
	count = 0;
	ft_parsing(form, ap, &count, 0);
	va_end(ap);
	return (count);
}

// int main()
// {
//     int a;
//     int c;
//     int x;

//     a = ft_printf("%x", -1);
//     printf("\n");
//     x = printf("%x", -1);
//     printf("\n------------------------");
//     printf("\nla longueur de mon printf : %d", a);
//     printf("\nla longueur du vrai printf : %d", x);
//     write(1, "\n", 1);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:40:26 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/23 11:48:19 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/* #include <stdio.h>

int	main()
{
	t_list *lst;
	t_list *new;
	t_list *test;

	lst = ft_lstnew("bim");
	new = ft_lstnew("stir");
	test = ft_lstnew("go");
	ft_lstadd_front(&lst, new);
	ft_lstadd_front(&new, test);
	printf("\nlongueur de la liste : %d", ft_lstsize(test));
} */
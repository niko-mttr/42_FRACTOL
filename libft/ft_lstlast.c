/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:57:55 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/21 15:42:21 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/* #include <stdio.h>

int	main()
{
	t_list *lst;
	t_list *new;
	t_list *test;
	t_list	*last;

	lst = ft_lstnew("bim");
	new = ft_lstnew("stir");
	test = ft_lstnew("go");
	ft_lstadd_front(&lst, new);
	ft_lstadd_front(&new, test);
	last = ft_lstlast(new);
	//printf("\nlongueur de la liste : %d", ft_lstsize(test));
	printf("\nle dernier element de la liste : %s", (char *) last->content);
} */
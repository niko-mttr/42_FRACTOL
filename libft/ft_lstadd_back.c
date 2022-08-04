/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:11:00 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/23 11:39:28 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (*lst && lst)
	{
		temp = *lst;
		temp = ft_lstlast(temp);
		temp->next = new;
	}
	else
		*lst = new;
}

/* #include <stdio.h>

int	main()
{
	t_list *begin;
	t_list *first;
	t_list *second;
	t_list *third;
	int		i;

	begin = (t_list*)malloc(sizeof(t_list));
	first = ft_lstnew("1");
	second = ft_lstnew("2");
	third = ft_lstnew("3");
	ft_lstadd_back(&begin, first);
	ft_lstadd_back(&begin, second);
	ft_lstadd_back(&begin, third);
	i = 0;
	while(first->next)
	{
		printf("%s", (char *)first->content);
		first = first->next;
		i++;
	}
	printf("%s", (char *)first->content);
}
 */
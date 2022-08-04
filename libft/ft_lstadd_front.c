/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:04:35 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/21 15:25:38 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>

int	main()
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*lecture;
	int		i;

	lecture = malloc(sizeof(t_list));
	lecture->next = third;
	first = ft_lstnew("1");
	second = ft_lstnew("2");
	third = ft_lstnew("3");
	ft_lstadd_front(&first, second);
	ft_lstadd_front(&second, third);
	i = 0;
	while (lecture->next )
	{
		printf("%s\n", (char *)lecture->content);
		lecture = lecture->next;
		i++;
	}
} */
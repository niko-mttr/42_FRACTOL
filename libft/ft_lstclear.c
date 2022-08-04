/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmattera <nmattera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 11:23:55 by nmattera          #+#    #+#             */
/*   Updated: 2022/05/23 11:40:35 by nmattera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = tmp;
	}
	lst = NULL;
}

/* #include <stdio.h>

void del(void *go)
{
    free(go);
}

int main()
{
	char	*str;
	char	*stir;
	char	*stor;
    t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*lecture;
    int     i;

	str = ft_strdup("bim");
	stir = ft_strdup("bam");
	stor = ft_strdup("bom");
    lecture = malloc(sizeof(t_list));
	lecture->next = third;
	first = ft_lstnew(str);
	second = ft_lstnew(stir);
	third = ft_lstnew(stor);
	ft_lstadd_back(&first, second);
	ft_lstadd_back(&first, third);
    ft_lstclear(&second,&del);
    i = 0;
    while(first->next)
    {
        printf("%s", (char *)first->content);
        first = first->next;
    }
    printf("%s", (char *)first->content);
}
 */
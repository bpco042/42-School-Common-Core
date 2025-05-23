/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
// takes the last node of a list
/*int main()
{
    t_list  *list;
    t_list  *node1;
    t_list  *node2;
    t_list  *node3;

    list = NULL;

    //creating the nodes with some content
    node1 = ft_lstnew(ft_strdup("First one"));
    node2 = ft_lstnew(ft_strdup("Second one"));
    node3 = ft_lstnew(ft_strdup("Last one"));

    //linking the nodes
    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);
    ft_lstadd_back(&list, node3);

    //printing the last one
    printf("%s\n", (char *)ft_lstlast(list)->content);

    ft_lstclear(&list, free);

    return (0);
}*/
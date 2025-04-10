/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/09 15:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst || !del)
        return;
    (*del)(lst->content);
    free(lst);
}
/*
//creating a printing function for the list
void    print_list(t_list *lst)
{
    while (lst)
    {
        printf("%s\n", (char *)lst->content);
        lst = lst->next;
    }
}

//creating a del function
void    del(void *content)
{
    free(content);
}

//create two new nodes and clear the first one
int main()
{
    t_list  *list;
    t_list  *node_1;
    t_list  *node_2;

    list = NULL;
    //creating nodes with some content
    node_1 = ft_lstnew(ft_strdup("First node"));
    node_2 = ft_lstnew(ft_strdup("Second node"));

    //linking nodes
    ft_lstadd_front(&list, node_1);
    ft_lstadd_front(&list, node_2);

    //print content before deletion
    print_list(list);

    ft_lstdelone(node_1, del);

    //print after deletion
    print_list(list);

    ft_lstdelone(node_2, del);

    return (0);
}*/
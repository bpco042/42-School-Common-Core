/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/10 15:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void(*del)(void *))
{
    t_list  *tmp;

    if (!lst || !del)
        return;
    while(*lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone((*lst), del);
        *lst = tmp;
    }
}
/*//creat a del function
void    del(void *content)
{
    free(content);
}
//adds new nodes in the beginning of the list and clear it all
int main()
{
    t_list  *list;
    t_list *node_1;
    t_list  *node_2;
    t_list *tmp; //temp pointer to go through the list

    list = NULL;
    //creating new nodes with some content
    node_1 = ft_lstnew(ft_strdup("First"));
    node_2 = ft_lstnew(ft_strdup("Second"));

    //adding nodes to the beginning of the list
    ft_lstadd_front(&list, node_1);
    ft_lstadd_front(&list, node_2);

    tmp = list;
    while (tmp)
    {
        printf("%s\n", (char *)tmp->content);
        tmp = tmp->next;//move to the next node
    }
    //clearing the list
    ft_lstclear(&list, del);
    printf("List after clearing\n");
        if(list == NULL)
        {
            printf("List is empty\n");
        }
        return (0);
}*/
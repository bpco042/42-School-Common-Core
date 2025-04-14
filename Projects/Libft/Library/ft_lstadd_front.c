/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/09 13:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd_front(t_list **lst, t_list *new)
{
    // if the list is empty or the new element is null, do nothing
    if (!lst || !new)
        return;
    // point the next of the new code to the head of the list
    new->next = *lst;
    //update the head of the list to be the new node
    *lst = new;
}
/*//adds new nodes in the beginning of the list
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
    return (0);
}*/

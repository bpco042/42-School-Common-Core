/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/09 13:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int i;

    i = 0;
    // if lst is empty, return 0
    if (!lst)
        return (0);
    // loops through the lst until the end
    while(lst)
    {
        // count nodes
        i++;
        // move the pointer to the next node
        lst = lst->next;
    }
    return (i);
}
//returns the size of a list
/*int main (void)
{
    t_list  *list;
    t_list  *node1;
    t_list  *node2;
    size_t  node_count;

    node_count = 0;

    list = NULL;

    //creating node with some content
    node1 =ft_lstnew(ft_strdup("First Node"));
    node2 = ft_lstnew(ft_strdup("Second Node"));

    //linking the nodes to the list
    ft_lstadd_back(&list, node1);
    ft_lstadd_back(&list, node2);

    //counting the nodes
    node_count = ft_lstsize(list);

    printf("List size is: %zu\n", node_count);
    return (0);
}*/

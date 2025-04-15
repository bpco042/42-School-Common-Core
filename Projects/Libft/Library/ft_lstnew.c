/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/09 13:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list  *ft_lstnew(void *content)
{
    t_list *new;
    // allocate memory for the new node
    new = (t_list *)malloc(sizeof(t_list));
    // check if it was successful
    if (!new)
        return (NULL);
    // set the node's content
    new->content = content;
    // initialize next pointer to NULL
    new->next = NULL;

    return (new);
}
//creates nodes to a list
/*int main(void)
{
    t_list  *list;
    t_list  *node1;

    list = NULL;

    node1 = ft_lstnew(ft_strdup("first node"));
    printf("%s\n", (char *)node1->content);

    free(node1->content);
    free(node1);

    return (0);
}*/

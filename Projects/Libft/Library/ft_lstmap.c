/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:22:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/10 16:55:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void*(*f)(void *), void (*del)(void *))
{
    t_list  *new_lst;
    t_list  *new_node;
 
    new_lst = NULL;
    new_node = NULL;
    // if 'f' or lst are null, do nothing
    if (!f || !lst)
        return (NULL);
    // iterates through the list until the end
    while (lst)
    {
        // apply 'f' on the current lst content and creating a new node
        new_node = ft_lstnew(f(lst->content));
        // check if the node was correctly created
        if (!new_node)
        {
            // if it isn't correctly created, apply clear and return NULL
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        // append the new node in the end of the new lst
        ft_lstadd_back(&new_lst, new_node);
        // move to the next node
        lst = lst->next;
    }
    return (new_lst);
}
//iterates through a list and applies a f function, creating a new list with the result
/*void    print_content(void *content)//printing function for the content
{
    printf("%s\n", (char *)content);
}

//to upper function
void    *toupper_lst(void *content)
{
    char    *str = (char *)content;
    char    *new_str = ft_strdup(str);
    int i;

    if (!new_str)
        return (NULL);

    for (i =  0; new_str[i]; i++)
    {
        new_str[i] = ft_toupper((unsigned char)new_str[i]);
    }
    return ((void *)new_str);
    
}

//del function
void    del(void *content)
{
    free(content);
}

//main function the shows the before and after
int main(void)
{
    t_list  *list;
    t_list  *node1;
    t_list  *node2;
    t_list  *new_list;

    list = NULL;

    //creating nodes with some content
    node1 = ft_lstnew(ft_strdup("first node"));
    node2 = ft_lstnew(ft_strdup("second node"));

    //linking the nodes
    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    //itering to print
    ft_lstiter(list, print_content);
  
    new_list = ft_lstmap(list, toupper_lst, del);
    ft_lstiter(new_list, print_content);
    ft_lstclear(&list, free);
    ft_lstclear(&new_list, free);
    return (0);
}*/

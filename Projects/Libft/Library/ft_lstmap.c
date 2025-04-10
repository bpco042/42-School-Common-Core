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

    if (!f || !lst)
        return (NULL);
    
    while (lst)
    {
        new_node = ft_lstnew(f(lst->content));
        if (!new_node)
        {
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_node);
        lst = lst->next;
    }
    return (new_lst);
}
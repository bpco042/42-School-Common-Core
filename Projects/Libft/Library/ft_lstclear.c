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
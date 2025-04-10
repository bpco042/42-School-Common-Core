/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:02:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/10 16:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstiter(t_list *lst, (*f)(void *))
{
    t_list *tmp;

    if (!lst)
        return;

    tmp = lst;
    while (tmp)
    {
        f(tmp->content);
        tmp = tmp->next;
    }
}
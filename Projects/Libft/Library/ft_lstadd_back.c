/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/09 15:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
// adds new nodes in the end of the list
/*int main()
{
    t_list  *list;
    t_list *node_1;
    t_list  *node_2;
    t_list *tmp; //temp pointer to go through the list

    list = NULL;
    //creating new nodes with some content
    node_1 = ft_lstnew(ft_strdup("First"));
    node_2 = ft_lstnew(ft_strdup("Second"));

    //adding nodes to the end of the list
    ft_lstadd_back(&list, node_1);
    ft_lstadd_back(&list, node_2);

    tmp = list;
    while (tmp)
    {
	printf("%s\n", (char *)tmp->content);
	tmp = tmp->next;//move to the next node
    }
    tmp = list;
    while (tmp)
    {
	t_list *next = tmp->next;
	free(tmp->content);
	free(tmp);
	tmp = next;
    }
    return (0);
}*/
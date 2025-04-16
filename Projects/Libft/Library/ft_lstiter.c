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

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
// iterates through a list and applies an f function to it's nodes
/*void    print_content(void *content) //a printing function for the content
{

    printf("%s\n", (char *)content);
}
int main()
{
    t_list  *list;
    t_list  *node1;
    t_list  *node2;

    list = NULL;

    //creating the nodes with some content
    node1 = ft_lstnew(ft_strdup("First node"));
    node2 = ft_lstnew(ft_strdup("Second node"));

    //linking the nodes to the list
    ft_lstadd_front(&list, node1);
    ft_lstadd_front(&list, node2);

    //itering through the list to print the content
    ft_lstiter(list, print_content);

    //clearing the memory
    ft_lstclear(&list, free);

    return (0);
}*/
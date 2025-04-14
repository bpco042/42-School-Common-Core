/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *str, int c)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        if (str[i] == (unsigned char)c)
            return ((char *)&str[i]);
        i++;
    }
    if (str[i] == (unsigned char)c)
        return ((char *)&str[i]);
    return (0);
}
/*//Finds the first occurrence of an int c in a str and return a pointer to the finding
int main(void)
{
    char    *str = "Veritasium";
    char    *ptr;
    int c = 'a';

    ptr = ft_strchr(str, c);
    printf("The result after finding %c is: %s\n", c, ptr);
    return (0);
}*/
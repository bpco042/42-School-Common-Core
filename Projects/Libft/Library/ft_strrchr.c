/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    int i;

    i = ft_strlen(str);
    while (i >= 0)
    {
        if(str[i] == (unsigned char)c)
            return ((char *)&str[i]);
        i--;
    }
    return (0);
}
//locates the last position of a char c in the str, returns a pointer to it's position
/*int main(void)
{
    char    *str = "Veritasium";
    char    *ptr;
    int c = 'a';

    ptr = ft_strrchr(str, c);
    printf("The result after findind %c is: %s\n", c, ptr);
    return (0);
}*/
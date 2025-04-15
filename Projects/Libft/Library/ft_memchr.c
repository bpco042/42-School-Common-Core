/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr(const void *str, int c, size_t n)
{
    size_t  i;
    unsigned char   *s;
    // cast of *str to unsigned char for byte comparison
    s = (unsigned char *)str;
    i = 0;
    // traverse while i is less then n
    while (i < n)
    {
        // check if the current byte is equal to c
        if (s[i] == (unsigned char)c)
            return ((void *)&s[i]);
        i++;
    }
    return (NULL);
}
//finds the first occurrence of c in n bytes of a str and return a poiter to the finding
/*int main(void)
{
    const char *str = "Veritasium";
    char    *ptr;
    int c = 'a';

    ptr = ft_memchr(str, c, ft_strlen(str));
    printf("The result after finding %c is %s\n:", c, ptr);
    return (0);
}*/

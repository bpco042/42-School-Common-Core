/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t len)
{
    size_t i;
    unsigned char *d;
    const unsigned char *s;
    // check if dest and src are null
    if (!dest || !src)
        return (NULL);
    // casting to it's possible to work byte-byte
    d = (unsigned char *)dest;
    s = (unsigned char *)src;
    // base case: if it's equal, return dest
    if (d == s)
        return (dest);
    // if dest is greater than src, copy from the end to avoid overlap
    if (d > s)
    {
        i = len;
        while (i > 0)
        {
            i--;
            d[i] = s[i];
        }
    }
    else
    {
        i = 0;
        // otherwise, copy from the beginning
        while (i < len)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}
//It works in a similar way to memcpy, but deals with memory overlap. If dest > src, it goes backwards; else it goes forward.
/*int main()
{
    char    str[] = "Veritasium";
    char    dest[6];

    ft_memmove(dest, str, 5);
    dest[5] = '\0';

    printf("%s\n", dest);
    return (0);
}*/

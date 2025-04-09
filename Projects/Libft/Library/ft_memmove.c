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

    if (!dest && !src)
        return (NULL);
    
    d = (unsigned char *)dest;
    s = (unsigned char *)src;

    if (d == s)
        return (dest);
    
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
        while (i < len)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}
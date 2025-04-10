/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t len)
{
    unsigned char *src_ptr = (unsigned char *)src;
    unsigned char *dest_ptr = (unsigned char *)dest;

    while (len > 0)
    {
        *dest_ptr = *src_ptr;
        src_ptr++;
        dest_ptr++;
        len--;
    }
    return (dest);
}
/*int main()
{
    char    dest[25];
    char    *src = "Hello";

    ft_memcpy(dest, src, ft_strlen(src) + 1);
    printf("%s\n", dest);
    return (0);
}*/
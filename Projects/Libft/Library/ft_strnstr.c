/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strnstr(const char *src, const char *find, size_t n)
{
    size_t i;
    size_t j;

    if (*find == '\0')
        return ((char *)src);
    
    i = 0;    
    while (src[i] && i < n)
    {
        j = 0;
        while (src[i + j] == find[j] && (i + j) < n)
        {
            j++;
        
            if (find[j] == '\0')
                return ((char *)(src + i));
        }
        i++;
    }
    return (0);
}
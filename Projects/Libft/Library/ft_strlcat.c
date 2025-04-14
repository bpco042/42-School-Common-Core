/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t  ft_strlcat(char *dest, const char *src, size_t n)
{
    size_t i;
    size_t j;

    i = 0;
    j = 0;

    if (!src || !dest)
        return (0);
    while (dest[i] && i < n - 1)
        i++;
    while (src[j] && i + j < n - 1)
    {
        dest[i + j] = src[j];
        j++;
    }
    if (i + j < n)
        dest[i + j] = '\0';
    return (i + ft_strlen(src));
}
/*//don´t allocate memory and just allocate the str in the end of dest with a delimitator of n size
int main(void)
{
    char    str[] = "Veritasium";
    char    dest[22] = "Science Channel ";
    size_t size = sizeof(dest);
    size_t  result;

    result = ft_strlcat(dest, str, size);
    printf("String%s\n", dest);
    printf("Length:%zu", result); //"zu is the correct format to print size_t elements. It's more portable between system architetures"
    return (0);
}*/
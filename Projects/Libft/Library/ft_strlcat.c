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
#include <stdio.h>
#include <string.h>  // Para comparar com a strlcat original
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
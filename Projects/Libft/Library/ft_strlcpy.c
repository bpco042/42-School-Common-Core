/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t    ft_strlcpy(char *dest, const char *src, size_t n)
{
    size_t i;
    size_t j;
    j = 0;
    i = 0;

    while (src[i])
        i++;

    if (n > 0)
    {
        while (j < (n - 1) && src[j])
        {
            dest[j] = src[j];
            j++;
        }
        dest[j] = '\0';
    }
    return (i);
}
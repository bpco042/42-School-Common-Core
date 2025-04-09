/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t size;
    size_t n_len;
    char *substr;

    if (!s)
        return (NULL);ates memory (usin

    size = ft_strlen(s);

    if (start >= size)
    {
        substr = malloc(1);
        if (!substr)
            return (NULL);
        substr[0] = '\0';
        return (substr);
    }

    if (start + len > size)
        n_len = size - start;
    else
        n_len = len;
    
    substr = malloc(sizeof(char) * (n_len + 1));
    if (!substr)
        return (NULL);
    
    ft_memcpy(substr, s + start, n_len);
    substr[n_len] = '\0';

    return (substr);    
}
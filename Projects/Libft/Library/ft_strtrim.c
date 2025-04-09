/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    int start;
    int end;
    char    *trimmed;
    int len;
 
    if (!s1 || !set)
        return (NULL);
    
    start = 0;
    end = ft_strlen(s1) - 1;

    while (s1[start] && ft_strchr(s1[start], set))
        start++;
    
    while (end >= start && ft_strchr(s1[end], set))
        end--;
    
    if (end < start)
        return (ft_strdup(""));

    len =  end - start + 1;

    trimmed = malloc(sizeof(char) * (len + 1));
    if (!trimmed)
        return (NULL);
    
    ft_memcpy(trimmed, &s1[start], end - start + 1);
    trimmed[end - start + 1] = '\0';
    return (trimmed);
}
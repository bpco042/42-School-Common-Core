/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int    i;
    char    *str;
    
    if (!s)
        return (NULL);
    str = malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while(s[i])
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}
char   tolower_f(unsigned int i, char c)
{
    (void)i;
    c = ft_tolower(c);
    return (c);
}
//iterates through the str and applies the function f, returning a new str with allocated memory
/*
int main(void)
{
    char    *str = "VeRiTaSiUm";
    printf("String before function: %s\n", str);
    printf("String after function: %s\n", ft_strmapi(str, tolower_f));
    return (0);
}*/
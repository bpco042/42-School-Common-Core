/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *new_str;
    int len_s1;
    int len_s2;

    if (s1 == NULL || s2 == NULL)
        return (NULL);
    
    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);

    new_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));

    if (!new_str)
        return (NULL);
    
    ft_memcpy(new_str, s1, len_s1);
    ft_memcpy(new_str + len_s1, s2, len_s2);
    new_str[len_s1 + len_s2] = '\0';

    return (new_str);
}
/*//return a str that is result of a concatenation of s1 and s2
int main(void)
{
    char    *str1 = "Veritasium ";
    char    *str2 = "Science Channel";

    printf("%s\n", ft_strjoin(str1, str2));
    return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_strlen(const char *str)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    return (len);
}
/*int main(void)
{
    char    *str = "Veritasium";
    char    str2[] = "Cappele";
    printf("Total length str: %d\n", ft_strlen(str));
    printf("Total length str2: %d\n", ft_strlen(str2));
    return (0);
}*/
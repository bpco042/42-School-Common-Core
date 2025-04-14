/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_isalnum(int n)
{
    if ((n >= '0' && n <= '9')
        || (n >= 'a' && n <= 'z')
            || (n >= 'A' && n <= 'Z'))
        return (1);
    else
        return (0);
}
/*
int main(void)
{
    printf("p is --> %d\n", ft_isalnum('p'));
    printf("P is --> %d\n", ft_isalnum('P'));
    printf("9 is --> %d\n", ft_isalnum('9'));
    printf("space is --> %d\n", ft_isalnum(' '));
    return (0);
}
*/
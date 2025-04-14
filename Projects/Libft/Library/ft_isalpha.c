/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_isalpha(int n)
{
    if ((n >= 'a' && n <= 'z')
        || (n >= 'A' && n <= 'Z'))
        return (1);
    else
        return (0);
}
/*int main (void)
{
    printf("p is --> %d\n", ft_isalpha('p'));
    printf("P is --> %d\n", ft_isalpha('P'));
    printf("8 is -- > %d\n", ft_isalpha('2'));
    printf("space is --> %d\n", ft_isalpha(' '));
    return (0);
}*/
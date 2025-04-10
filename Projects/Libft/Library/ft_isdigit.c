/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_isdigit(int n)
{
    if (n >= '0' && n <= '9')
        return (1);
    else
        return (0);
}
/*int main(void)
{
    printf("8 is --> %d\n", ft_isdigit('8'));
    printf("P is --> %d\n", ft_isdigit('P'));
    printf("0 is --> %d\n", ft_isdigit('0'));
    printf("space is --> %d\n", ft_isdigit(' '));
    return (0);
}*/
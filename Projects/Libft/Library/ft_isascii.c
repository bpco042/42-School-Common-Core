/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int n)
{
	if (n >= 0 && n <= 127)
		return (1);
	else
		return (0);
}
/*int main(void)
{
    printf("p is --> %d\n", ft_isascii('p'));
    printf("P is --> %d\n", ft_isascii('P'));
    printf("0 is --> %d\n", ft_isascii('0'));
    printf("space is --> %d\n", ft_isascii(' '));
    return (0);
}*/
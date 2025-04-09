/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/09 13:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_itoa(int n)
{
    char    *nb;
    long num;
    long temp;
    size_t len;

    len = 1;
    num = n;
    if(n < 0)
    {
        num = -num;
        len++;
    }
    temp = num;
    while (temp >= 10)
    {
        temp = temp / 10;
        len++;
    }
    nb = malloc(sizeof(char) * (len + 1));
    if (!nb)
        return (NULL);
    
    nb[len] = '\0';

    if (n == 0)
        nb[0] = '0';

    if (n < 0)
        nb[0] = '-';

    while (num > 0)
    {
        nb[--len] = (num % 10) + '0';
        num = num / 10;
    }
    return (nb);

}
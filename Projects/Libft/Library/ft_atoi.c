/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int result;

    i = 0;
    sign = 1;
    result = 0;

    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }    
    else
    {
        i++;
    }

    while (str[i] && str[i] >= '0' && str[i] <= '9')
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    return (result * sign);
}
/*Converts string to integer
int main()
{
    const char *c = "-2329";
    int result;

    result = ft_atoi(c);
    printf("%d\n", result);
}
*/
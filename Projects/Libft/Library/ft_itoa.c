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
    // Set the sign if the nb is negative
    if(n < 0)
    {
        num = -num;
        len++;
    }
    temp = num;
    // Count how many digits are needed
    while (temp >= 10)
    {
        temp = temp / 10;
        len++;
    }
    // Allocates memory to receive the str
    nb = malloc(sizeof(char) * (len + 1));
    // Check if the allocation was successful
    if (!nb)
        return (NULL);
    // Set a null terminator in the final of the str
    nb[len] = '\0';
    // handle zero explicitly
    if (n == 0)
        nb[0] = '0';
    // if nb is negative, sets the sign in the first position
    if (n < 0)
        nb[0] = '-';

    // fill digits from the end to the beginning
    while (num > 0)
    {
        nb[--len] = (num % 10) + '0';
        num = num / 10;
    }
    return (nb);

}
/*Converts a int to str
int main ()
{
    int c = -25458;
    char    *result;

    result = ft_itoa(c);
    printf("%s\n", result);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
    // casting so the comparison can be done byte-byte
    unsigned char *p1 = (unsigned char *)ptr1;
    unsigned char *p2 = (unsigned char *)ptr2;

    // loops through the informed size
    while (n > 0)
    {
        // compare the pointers
        if (*p1 != *p2)
            // if it's different, returns the difference
            return (*p1 - *p2);
        p1++;
        p2++;
        n--;
    }
    return (0);
}
/*int main()
{
    char    *str1 = "Veritasium";
    char    *str2 = "Veritasium";
    char    *str3 = "Veritaxium";

    int result1 = ft_memcmp(str1, str2,ft_strlen(str1) + 1);
    if (result1 == 0)
        printf("They are equal\n");
    else
        printf("They are not equal\n");

    int result2 = ft_memcmp(str2, str3, ft_strlen(str2) + 1);
    if (result2 == 0)
        printf("They are equal\n");
    else
        printf("They are not equal\n");
    return (0);
}*/

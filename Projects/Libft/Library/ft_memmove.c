/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = len;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
// Seems memcpy but deals with memory overlap.
/*int main(void)
{
    char buffer1[20] = "Hello, World!";
    ft_memmove(buffer1 + 7, buffer1, 5);
    printf("Test 1 (overlap): %s\n", buffer1);

    char buffer2[20] = "Hello, World!";
    ft_memmove(buffer2 + 7, buffer2 + 7, 6);
    printf("Test 2 (no overlap): %s\n", buffer2);

    char buffer3[50] = "This is a much larger buffer for testing memmove!";
    ft_memmove(buffer3 + 10, buffer3, 10);
    printf("Test 3 (large buffer): %s\n", buffer3);

    char buffer4[20] = "Move to start!";
    ft_memmove(buffer4, buffer4 + 5, 10);
    printf("Test 4 (move to start): %s\n", buffer4);

    char buffer5[20] = "Empty source";
    ft_memmove(buffer5, "", 0);
    printf("Test 5 (empty source): %s\n", buffer5);

    char buffer6[20] = "No change!";
    ft_memmove(buffer6, buffer6, 10);
    printf("Test 6 (same source and destination): %s\n", buffer6);
    return 0;
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*src_ptr;
	unsigned char	*dest_ptr;

	src_ptr = (unsigned char *)src;
	dest_ptr = (unsigned char *)dest;
	while (len > 0)
	{
		*dest_ptr = *src_ptr;
		src_ptr++;
		dest_ptr++;
		len--;
	}
	return (dest);
}
/*int main(void)
{
    char dest1[50];
    char dest2[50] = "original";
    char dest3[50];
    int  binary_dest[4];
    int  binary_src[] = {10, 20, 30, 40};
    char same_ptr[] = "SelfCopy";
    char overlap[] = "OverlapTest";

    // Basic test with a regular string
    ft_memcpy(dest1, "Hello, 42!", ft_strlen("Hello, 42!") + 1);
    printf("Basic: %s\n", dest1);

    // Test with length = 0 (destination should remain unchanged)
    ft_memcpy(dest2, "ShouldNotChange", 0);
    printf("Len 0: %s\n", dest2);

    // Test with special characters
    ft_memcpy(dest3, "42 @Porto!", ft_strlen("42 @Porto!") + 1);
    printf("Symbols: %s\n", dest3);

    // Test copying to the same memory (should be safe but redundant)
    ft_memcpy(same_ptr, same_ptr, ft_strlen(same_ptr) + 1);
    printf("Same ptr: %s\n", same_ptr);

    // Overlapping memory regions (undefined behavior with memcpy)
    ft_memcpy(overlap + 2, overlap, 5);
    printf("Overlap (undefined): %s\n", overlap);

    return 0;
}*/

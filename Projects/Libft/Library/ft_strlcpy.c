/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (src[i])
		i++;
	// cpy while n is greater than zero
	if (n > 0)
	{
		// while j is less than size - 1 (last valid position) and src did not come to an end
		while (j < (n - 1) && src[j])
		{
			
			dest[j] = src[j];
			j++;
		}
		dest[j] = '\0';
	}
	return (i);
}
/*int main(void)
{
    char    str[] = "Veritasium";
    char    dest[20];
    size_t  size = 5;
    size_t  result;

    result = ft_strlcpy(dest, str, size);
    printf("String: %s\n", dest);
    printf("Length: %zu\n", result);
    return (0);
}*/

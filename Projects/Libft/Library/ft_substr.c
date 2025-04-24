/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	size_t	n_len;
	char	*substr;
	//base case to avoid errors
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	// check if the start position is beyond the size
	if (start >= size)
	{
		// there's no room to fit it, so allocate memory to \0
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	// adjust the size of the substr in case it goes beyond the size of the original; else, remains the same
	if (start + len > size)
		n_len = size - start;
	else
		n_len = len;
	// allocates memory to the substr + terminator 
	substr = malloc(sizeof(char) * (n_len + 1));
	if (!substr)
		return (NULL);
	// copy all from the start until whats was defined at n_len
	ft_memcpy(substr, s + start, n_len);
	substr[n_len] = '\0';
	return (substr);
}
// allocates memory to a substr and returns it from the int start til len
/*int main(void)
{
    char    *str = "Veritasium";
    char    *ptr;

    printf("original str: %s\n", str);
    ptr = ft_substr(str, 3, ft_strlen(str));
    printf("substring: %s\n", ptr);
    free(ptr);
    printf("original str: %s\n", str);
    ptr = ft_substr(str, 1, 8);
    printf("substring: %s\n", ptr);
    free(ptr);
    return (0);
}*/

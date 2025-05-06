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

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (start + len > size)
		n_len = size - start;
	else
		n_len = len;
	substr = malloc(sizeof(char) * (n_len + 1));
	if (!substr)
		return (NULL);
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
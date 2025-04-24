/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;
	//base case
	if (*find == '\0')
		return ((char *)src);
	i = 0;
	//loops while str is valid and index i > than size
	while (src[i] && i < n)
	{
		//second variable to check the find
		j = 0;
		// loops through the actual position of str + index j and checks if the char of index j in find is equal. To secure the operation, limits it until index i and j are greater than size
		while (src[i + j] == find[j] && (i + j) < n)
		{
			j++;
			//if we reach the end of find, we found the complete str, so we return a pointer to it's beginning
			if (find[j] == '\0')
				return ((char *)(src + i));
		}
		//otherwise, move index i forward
		i++;
	}
	return (0);
}
// returns de first occurrence of find str in the src.
/*int main(void)
{
    char    *str = "Veritasium Science Channel";
    char    *find = "Science";

    printf("Result is: %s\n", ft_strnstr(str, find, ft_strlen(str)));
    return (0);
}*/

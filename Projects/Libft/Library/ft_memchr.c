/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	// cast the str so we can work through every byte
	s = (unsigned char *)str;
	// while position is greater than n, keep going
	while (i < n)
	{
		//check if the s position is equal to c
		if (s[i] == (unsigned char)c)
			//return the position of the finding (start position of s + how much it moved i)
			return (s + i);
		i++;
	}
	return (0);
}
//finds the first occurrence of c in n bytes of a str
// int main(void)
// {
//     const char *str = "Veritasium";
//     char    *ptr;
//     int c = 'a';

//     ptr = ft_memchr(str, c, ft_strlen(str));
//     printf("The result after finding %c is %s:\n", c, ptr);
//     return (0);
// }

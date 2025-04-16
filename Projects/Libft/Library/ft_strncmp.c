/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str_ref, const char *str_base, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (str_ref[i] != str_base[i])
			return ((unsigned char)str_ref[i] - (unsigned char)str_base[i]);
		if (str_ref[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
// compares n chars of the passed two strs and returns the difference
/*int main(void)
{
    char    *str = "Veritasium";
    char    *str1 = "VeriTasium";

    printf("Compared strings: %s and %s\n", str, str1);
    printf("Result: %d\n", ft_strncmp(str, str1, sizeof(str)));
    return (0);
}*/
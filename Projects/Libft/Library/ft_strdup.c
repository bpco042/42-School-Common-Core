/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dup;

	//calculate the size of src to future memory allocation + 1
	len = ft_strlen(src) + 1;
	//allocate memory to the duplicate
	dup = malloc(len);
	//check if everything is fine
	if (!dup)
		return (NULL);
	// copy src to dup until the len limitation (including \0)
	ft_memcpy(dup, src, len);
	return (dup);
}
// creates a dinamic allocated duplicate
/*int main(void)
{

    printf("The duplicate is: %s\n", ft_strdup("Veritasium"));
    return (0);
}*/

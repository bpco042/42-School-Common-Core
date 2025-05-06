/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:29:10 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/10 11:45:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// apply a function to each char of the str
/*void    tolower_f(unsigned i, char *c)
{
    (void)i;
    *c = ft_tolower(*c);
}

int main(void)
{
    char    str[] = "VeRiTaSiUm";

    printf ("before application of f: %s\n", str);
    ft_striteri(str, tolower_f);
    printf("after application: %s\n", str);

    return (0);
}*/
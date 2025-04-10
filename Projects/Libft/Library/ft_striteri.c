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

void    ft_striteri(char *s, void(*f)(unsigned int, char*))
{
    unsigned int    i;

    i = 0;
    if (!s)
        return;
    while (s[i])
    {
        f(i, &s[i]);
        i++;
    }
}
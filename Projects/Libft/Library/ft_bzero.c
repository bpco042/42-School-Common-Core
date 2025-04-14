/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *dest, size_t len)
{
    //#uses memset to make the zerofication of the positions
    ft_memset(dest, 0, len);
}
//sets n number of positions into zero
/*int main() {
    char str[10] = "Hello1234";

    printf("before %s\n", str);
    ft_bzero(str, 5);
    printf("after %s\n", str);

    return 0;
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    char    c;

    if (n == -2147483648)
    {
        write (fd, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write (fd, "-", 1);
        n = -n;
    }
    if(n >= 10)
    {
        ft_putnbr_fd((n / 10), fd);
    }
    c = (n % 10) + '0';
    write (fd, &c, 1);
}
/*int main()
{
    ft_putnbr_fd(-357, 1);
    return (0);
}*/
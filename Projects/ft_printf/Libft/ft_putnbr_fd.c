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

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	c = (n % 10) + '0';
	write(fd, &c, 1);
}
/*int main()
{
    int fd = 1; // Output to standard output (stdout)

    ft_putnbr_fd(42, fd);
    write(fd, "\n", 1);

    ft_putnbr_fd(-42, fd);
    write(fd, "\n", 1);

    ft_putnbr_fd(0, fd);
    write(fd, "\n", 1);

    ft_putnbr_fd(2147483647, fd);
    write(fd, "\n", 1);

    ft_putnbr_fd(-2147483648, fd);
    write(fd, "\n", 1);

    return 0;
}*/
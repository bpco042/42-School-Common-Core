/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 11:40:00 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/10 11:55:12 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, &(*s++), 1);
	write(fd, "\n", 1);
}
// Outputs a str with a given file descriptor with a new line at the end
/*int main()
{
    char    *s = "Hello";
    ft_putendl_fd(s, 1);
    return (0);
}*/
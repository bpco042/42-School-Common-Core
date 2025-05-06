/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/05/02 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_len(char c)
{
	write(1, &c, 1);
	return (1);
}
//the same putchar, but returning the lenght

int	ft_putstr_len(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write (1, str, ft_strlen(str));
	return (ft_strlen(str));
}
//the same putstr but returning the lenght

int	ft_putnbr_len(int num)
{
	int		len;
	char	*str;

	str = ft_itoa(num);
	len = ft_putstr_len(str);
	free(str);
	return (len);
}
// putnbr returning the lenght
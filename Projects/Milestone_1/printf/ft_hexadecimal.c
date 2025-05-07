/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/05/05 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		num = num / 16;
		len++;
	}
	return (len);
}

void	ft_puthex(unsigned int num, const char spec)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, spec);
		ft_puthex(num % 16, spec);
	}
	else
	{
		if (num <= 9)
			ft_putchar_len((num + '0'));
		else
		{
			if (spec == 'x')
				ft_putchar_len((num - 10 + 'a'));
			if (spec == 'X')
				ft_putchar_len((num - 10 + 'A'));
		}
	}
}

int	ft_hex(unsigned int num, const char spec)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, spec);
	return (ft_hexlen(num));
}

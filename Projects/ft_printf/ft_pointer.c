/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/05/02 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}

int	ft_putptr(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr >= 16)
	{
		len += ft_putptr(ptr / 16);
		len += ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			len += ft_putchar_len(ptr + '0');
		else
			len += ft_putchar_len(ptr - 10 + 'a');
	}
	return (len);
}

int	ft_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += ft_putstr_len("(nil)");
		return (len);
	}
	len = ft_putstr_len("0x");
	len += ft_putptr(ptr);
	return (len);
}

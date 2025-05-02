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
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16;
	}
	return (len);
}
int	ft_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_len(ptr + '0');
		else
			ft_putchar_len(ptr - 10 + 'a');
	}
	return (ft_ptrlen(ptr));
}
int	ft_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		len += ft_pustr_len("(NULL)");
		return (len);
	}
	len = putstr_len("0x");
	len += ft_putptr(ptr);
	return (len);
}
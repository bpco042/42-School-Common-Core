/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/05/02 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_spec(va_list args, const char spec)
{
	if (spec == '%')
		return (ft_putchar_len('%'));
	if (spec == 'c')
		return (ft_putchar_len(va_arg(args, int)));
	else if (spec == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	else if (spec == 'p')
		return (ft_pointer((unsigned long long)va_arg(args, void *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr_len(va_arg(args, int)));
	else if (spec == 'u')
		return (ft_unsigned(va_arg(args, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (ft_hex(va_arg(args, unsigned int), spec));
	else
		return (0);
}

int	ft_printf(const char *spec, ...)
{
	va_list	args;
	size_t	i;
	int		len;

	if (!spec)
		return (-1);
	va_start(args, spec);
	i = 0;
	len = 0;
	while (spec[i])
	{
		if (spec[i] == '%' && spec[i + 1])
		{
			len += ft_printf_spec(args, spec[i + 1]);
			i++;
		}
		else
			len += ft_putchar_len(spec[i]);
		i++;
	}
	va_end(args);
	return (len);
}

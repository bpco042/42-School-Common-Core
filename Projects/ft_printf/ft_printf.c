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
	switch (spec)
	{
	case 'c':
		return (ft_putchar_len(va_arg(args, int)));
	case 's':
		return (ft_putstr_len(va_arg(args, char *)));
	case 'p':
		return (ft_pointer(va_arg(args, unsigned long long)));
	case 'd':
	case 'i':
		return (ft_putnbr_len(va_arg(args, int)));
	case 'u':
		return (ft_unsigned(va_arg(args, unsigned int)));
	case 'x':
	case 'X':
		return (ft_hex(va_arg(args, unsigned int), spec));
	default:
		return (0);
	}
}

int	ft_printf(const char *spec, ...)
{
	va_list	args;
	size_t	i;
	int	len;
	int	printed;

	if (!spec)
		return (-1);
	va_start(args, spec);
	i = 0;
	len = 0;
	while (spec[i])
	{
		if (spec[i] == '%' && spec[i + 1])
		{
			printed = ft_printf_spec(args, spec[i + 1]);
			if (printed == 0 && spec[i + 1] != '%')
				len += ft_putchar_len('%');
			else
				len += printed;
			i++;
		}
		else
			len += ft_putchar_len(spec[i]);
		i++;
	}
	va_end(args);
	return (len);
}
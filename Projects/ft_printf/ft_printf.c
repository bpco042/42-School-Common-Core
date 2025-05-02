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

//function to select the correct specifier and call the appropriate print function
int	ft_printf_spec(va_list args, const char spec)
{
	// If the spec is '%', print a literal '%'
	if (spec == '%')
		return (ft_putchar_len('%'));

	// Switch statement to select the correct function based on the specifier
	switch (spec)
	{
	case 'c':
		// Retrieve an int from args and print it
		return (ft_putchar_len(va_arg(args, int)));
	case 's':
		// Retrieve a char* from args and print it
		return (ft_putstr_len(va_arg(args, char *)));
	case 'p':
		// Retrieve an unsigned long long and print the address
		return (ft_pointer(va_arg(args, unsigned long long)));
	case 'd':
	case 'i':
		// Retrieve an int and print it
		return (ft_putnbr_len(va_arg(args, int)));
	case 'u':
		// Retrieve an unsigned int and print it
		return (ft_unsigned(va_arg(args, unsigned int)));
	case 'x':
	case 'X':
		// Retrieve an unsigned int and print it in lowercase or uppercase
		return (ft_hex(va_arg(args, unsigned int), spec));
	default:
		// If spec is not recognized, return 0
		return (0);
	}
}
//main function of printf
int	ft_printf(const char *spec, ...)
{
	va_list	args;
	size_t	i;
	int	len;
	int	printed;

	//verify the validity of spec
	if (!spec)
		return (-1);
	//initializes the variadic variable with va_start
	va_start(args, spec);
	i = 0;
	len = 0;

	//loop through the string spec while the current char is not null
	while (spec[i])
	{
		//Check if the current char is '%' and there is a next char
		if (spec[i] == '%' && spec[i + 1])
		{
			//Call function to handle the format spec
			//passing the args and the next char as specifier
			printed = ft_printf_spec(args, spec[i + 1]);

			// If nothing was printed and the next char is not the identifier '%'
			if (printed == 0 && spec[i + 1] != '%')
				// Print a literal '%' and add its length to the total
				len += ft_putchar_len('%');
			else
				// Otherwise, add the number of chars printed by the function
				len += printed;
			// Move the index forward to skip the format specifier
			i++;
		}
		else
			// If the current char is not '%', just print it and add its length
			len += ft_putchar_len(spec[i]);
		// Move to the next char in the string
		i++;
	}
	va_end(args);
	return (len);
}

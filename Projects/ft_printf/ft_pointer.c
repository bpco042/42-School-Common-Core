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

// Function to calculate the length of a pointer, in hexadecimal digits
int	ft_ptrlen(unsigned long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		len++;
		ptr = ptr / 16; // Divide by 16 to shift one hex digit
	}
	return (len);
}

// Recursive function to print a pointer's hex representation
int	ft_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		// Recursively print higher (/) and lower (%) hex digits
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		// Print a single hex digit
		if (ptr <= 9)
			ft_putchar_len(ptr + '0'); // For 0 - 9
		else
			ft_putchar_len(ptr - 10 + 'a'); // For letters a - f
	}
	return (ft_ptrlen(ptr)); // Return length
}

// function to print a pointer value in the form 0x... and return the printed length
int	ft_pointer(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
	{
		// Handle the  null pointer
		len += ft_putstr_len("(NULL)");
		return (len);
	}
	len = ft_putstr_len("0x"); // Print "0x" prefix for pointers
	len += ft_putptr(ptr); // Print the hex value
	return (len); // Return the total number of chars printed
}

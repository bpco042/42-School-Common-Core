/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/05/02 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to print a single char and return its length (always 1)
int	ft_putchar_len(char c)
{
	write(1, &c, 1); // Print an char
	return (1); // Return the length of the printed char
}

// Function to print a string and return its printed length
int	ft_putstr_len(char *str)
{
	// Handle the null case
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	// Otherwise, print the current string 
	write (1, str,ft_strlen(str));
	return (ft_strlen(str)); // Return the number of chars printed
}

// Function to print an int and return the number of chars printed
int	ft_putnbr_len(int num)
{
	int	len;
	char	*str;

	// Convert int to a string
	str = ft_itoa(num);
	// Print the string and get the number of chars printed
	len = ft_putstr_len(str);
	// Free the allocated memory
	free(str);
	return (len); // Return the length of the printed chars
}

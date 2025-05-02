/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft__unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/05/02 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Auxiliary function to calculate the number of digits in an unsigned int
int	ft_unlen(unsigned int num)
{
	int	len;

	len = 0;

	// Loop until all digits are counted
	while (num != 0)
	{
		len++;
		num = num /10; // Remove the last digit
	}
	// Return the number of digits
	return (len);
}

// Function to convert an unsigned int to a string
char	*ft_utoa(unsigned int num)
{
	char	*str;
	int	len;

	// Get the number of digits
	len = ft_unlen(num);

	// Allocate memory fro the string +1
	str = malloc((len + 1) * sizeof(char *));

	// Check if the allocation was successful
	if (!str)
		return (NULL);
	// Add a null terminator in the string
	str[len] = '\0';

	// Convert the number to a string from the end to the beginning
	while (num != 0)
	{
		str[len - 1] = num % 10 + '0'; // Get the last digit and convert it to a char
		num = num / 10; // Remove the last digit
		len--;
	}
	return (str); // Return the string
}

// Main function to print an unsigned int and return the number of chars
int	ft_unsigned(unsigned int num)
{
	int	len;
	char	*str;

	len = 0;

	// Handle the zero case
	if (num == 0)
		len += write(1, "0", 1);
	else
	{
		// Convert number to a string
		str = ft_utoa(num);
		// Print the string and store the length
		len += ft_putstr_len(str);
		// Free the allocated memory
		free(str);
	}
	return (len); // Return the total number of chars printed
}

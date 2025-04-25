/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/09 13:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// count digits so we can allocate the correct amount of memory
static int	count_digit(long n)
{
	int	len;

	len = 1;
	// negative nb is changed to positive and we add one more len space to the sign
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	// while there's one more digit, break it dividing per 10 and increment the len 
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*nb;
	long	num;
	size_t	len;
	//cast from int to long, so we avoid overflow in the extreme cases
	num = (long)n;
	//count the size of the nb + 1, so we can allocate memory
	len = count_digit(num) + 1;
	//allocate memory to var nb
	nb = (char *)malloc(sizeof(char) * len);
	if (!nb)
		return (NULL);
	//handles negative cases
	if (num < 0)
	{
		num = num * -1;
		nb[0] = '-';
	}
	nb[--len] = '\0';
	// handle explicitly the zero case
	if (num == 0)
		nb[0] = '0';
	// handle positive cases
	while (num)
	{
		nb[--len] = (num % 10) + '0';
		num = num / 10;
	}
	return (nb);
}
// Converts int to a str
/*int main()
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(123));
	printf("%s\n", ft_itoa(-123));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
}*/

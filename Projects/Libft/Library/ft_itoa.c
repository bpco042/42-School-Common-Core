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

int	count_digit(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
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

	num = (long)n;
	len = count_digit(num) + 1;
	nb = (char *)malloc(sizeof(char) * len);
	if (!nb)
		return (NULL);
	if (num < 0)
	{
		num = num * -1;
		nb[0] = '-';
	}
	nb[--len] = '\0';
	if (num == 0)
		nb[0] = '0';
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
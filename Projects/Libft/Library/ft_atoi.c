/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/15 15:47:34 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
// converts str to int
/*int main()
{
    printf("Resultado 1: %d\n", ft_atoi("12345"));
    printf("Resultado 2: %d\n", ft_atoi("-12345"));
    printf("Resultado 3: %d\n", ft_atoi("+12345"));
    printf("Resultado 4: %d\n", ft_atoi("   12345"));
    printf("Resultado 5: %d\n", ft_atoi("\t\n\v\f\r12345"));
    printf("Resultado 6: %d\n", ft_atoi("12345abc"));
    printf("Resultado 7: %d\n", ft_atoi("123abc45"));
    printf("Resultado 8: %d\n", ft_atoi("2147483647"));
    printf("Resultado 9: %d\n", ft_atoi("-2147483648"));

    return 0;
}*/

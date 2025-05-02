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

int	ft_unlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num /10;
	}
	return (len);
}

char	*ft_utoa(unsigned int num)
{
	char	*str;
	int	len;

	len = ft_unlen(num);
	str = malloc((len + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (num != 0)
	{
		str[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	ft_unsigned(unsigned int num)
{
	int	len;
	char	*str;

	len = 0;
	if (num == 0)
		len += write(1, "0", 1);
	else
	{
		str = ft_utoa(num);
		len += ft_putstr_len(str);
		free(str);
	}
	return (len);
}

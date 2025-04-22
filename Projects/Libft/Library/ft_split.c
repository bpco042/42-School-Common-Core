/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/09 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	memsize(int i, const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[i] && str[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[i] && str[i] != c)
	{
		count++;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int	ft_fill(char const *str, char c, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			result[j] = malloc(memsize(i, str, c) + 1);
			if (!result[j])
			{
				while (j-- > 0)
					free(result[j]);
				free(result);
				return (1);
			}
			ft_strcpy(result[j], &str[i], c);
			i = i + memsize(i, str, c);
			j++;
		}
		else
			i++;
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**result;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	result = malloc((len + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (ft_fill(s, c, result))
		return (NULL);
	result[len] = NULL;
	return (result);
}
// ft_split - split a block str into different str separated by c
/*int main()
{
    char *str = "Hello World 42";
    char c = ' ';
    char **split = ft_split(str, c);

    printf("Before split: %s\n", str);

    for (int i = 0; split[i] != NULL; i++)
    {
	printf("Word %d: %s\n", i + 1, split[i]);
	free(split[i]);
    }

    free(split);
    return 0;
}*/
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

static int	word_counter(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	*word_dup(const char *s, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split_words;
	int		i;
	int		start;
	int		j;

	if (!s)
		return (NULL);
	split_words = malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!split_words)
		return (NULL);
	i = -1;
	j = 0;
	start = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == ft_strlen(s)))
		{
			split_words[j++] = word_dup(s, start, i);
			start = -1;
		}
	}
	split_words[j] = 0;
	return (split_words);
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
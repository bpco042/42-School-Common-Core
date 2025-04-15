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

static int word_counter(char const *s, char c)
{
    int count = 0;

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
    }
    return (count);
}

static char *get_word(char const *s, char c)
{
    int len = 0;
    char *word;

    while (*s == c)
        s++;

    while (s[len] && s[len] != c)
        len++;
    
    word = malloc(len + 1);
    if (!word)
        return (NULL);
    
    for (int i = 0; i < len; i++)
        word[i] = s[i];
    word[len] = '\0';

    return (word);
}

char    **ft_split(char const *s, char c)
{
    char **split_words;
    int i = 0;

    if (!s)
        return (NULL);

    int word_count = word_counter(s, c);
    split_words = malloc(sizeof(char *) * (word_count + 1));
    if (!split_words)
        return (NULL);

    while (*s)
    {
        if (*s != c)
        {
            split_words[i] = get_word(s, c);
            if (!split_words[i])
            {
                while (i > 0)
                    free(split_words[--i]);
                free(split_words);
                return (NULL);
            }
            i++;

            // Pula a palavra recém-pega
            while (*s && *s != c)
                s++;
        }
        else
            s++; // avança o separador
    }

    split_words[i] = NULL;
    return (split_words);
}
/*//ft_split separades a block of str into various words delimited by a delimitator c
int main ()
{
    char    *str = "Hello World 42";
    char    c = " ";
    char    **split = ft_split(str, c);
    int i;
        
    printf("before split: %s\n", str);
    while ()
    printf("after split: %s\n");

    for (int i = 0; split[i]; i++)
    {
        printf("  -%s\n", split[i]);
        free(split[i]);
    }
    free(split[i]);
    return (0);
}*/

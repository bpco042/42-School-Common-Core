/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/23 15:47:34 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* to find char c into str.
It's used to find \n in the line to read */
size_t	ft_strchr_len(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

/* Function to join two strings and return a new str
containing the combination*/
char	*ft_strjoin_dup(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*strjoin;
	size_t	len1;
	size_t	len2;

	i = 0;
	j = 0;
	if (!str1)
		str1 = "";
	if (!str2)
		return (NULL);
	len1 = ft_strchr_len(str1, '\0');
	len2 = ft_strchr_len(str2, '\0');
	strjoin = malloc(sizeof(char) * (len1 + len2 +1));
	if (!strjoin)
		return (NULL);
	while (i < len1)
	{
		strjoin[i] = str1[i];
		i++;
	}
	while (j < len2)
	{
		strjoin[i] = str2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}

/* Function to read a line of text from a FD
 and returns a str. It allocates memory and returns brings
 the content of a file */
char	*ft_line_allocation(int fd, char *str)
{
	char	*buffer;
	ssize_t	status;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	status = 1;
	while (!(ft_strchr_len(str, '\n')) && status > 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[status] = '\0';
		str = ft_strjoin_dup(str, buffer);
		if (!str)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (str);
}

/* Function to extract the next line of text from a str
and returns a new str with the next line*/
char	*ft_next_line(char *str)
{
	char	*new;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	if (!str || str[line_len] == 0)
		return (NULL);
	while (str[line_len] && str[line_len] != '\n')
		line_len++;
	new = malloc(line_len + 2);
	if (!new)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	new[i] = '\0';
	return (new);
}

/* Function to remove read line of text from the str */
char	*ft_rem_line(char *line)
{
	char	*str;
	size_t	i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	i++;
	str = ft_strjoin_dup(&line[i], "");
	free(line);
	return (str);
}

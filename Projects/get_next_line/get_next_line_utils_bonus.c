/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/23 18:47:34 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* to find char c into str.
It's used to find \n in the line to read */
char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_len(str)]);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
/* Function to calculate the len of the line to read */
size_t	ft_len(char *str)
{
	size_t	i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
/* Function to join two strings and return a new str containing the combination*/
char	*ft_strjoin( char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*strjoin;

	if (!str2)
		return (NULL);
	if (!str1)
		return (ft_strdup(str2));
	strjoin = (char *)malloc(sizeof(char) * (ft_len(str1) + ft_len(str2) + 1));
	if (!strjoin)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
		strjoin[j++] = str1[i++];
	i = 0;
	while (str2[i])
		strjoin[j++] = str2[i++];
	strjoin[j] = '\0';
	return (strjoin);
}

/* Function to create a dinamic allocated duplicate*/

char	*ft_strdup(char *str)
{
	size_t	len;
	char	*dup;
	size_t	i;

	if (!str)
		return (NULL);
	len = ft_len(str) + 1;
	dup = malloc(len);
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
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
	while (!(ft_strchr(str, '\n')) && status > 0)
	{
		status = read(fd, buffer, BUFFER_SIZE);
		if (status == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[status] = '\0';
		str = ft_strjoin(str, buffer);
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
	while (str[i] && str[i] != '\n')
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

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	i++;
	str = ft_strdup(&line[i]);
	free(line);
	return (str);
}
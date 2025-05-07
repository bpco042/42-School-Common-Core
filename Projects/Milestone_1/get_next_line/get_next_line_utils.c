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

/*to find char c into str. This function returns a pointer to the first
occurrence of a character in a string, or NULL if the character is not found.
Used to find '\n' in the line to read.*/

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	// Check the validity of str
	if (!str)
		return (0);
	// If we're looking for the \0, return a pointer to the end of the str
	if (c == '\0')
		return ((char *)&str[ft_len(str)]);
	// Traverse the str searching for c
	while (str[i])
	{
		// Check the str index to c
		if (str[i] == (char) c)
			// If it matches, return a pointer to that position
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

/*This function joins two strings together and returns a new string containing
the combined strings.*/

char	*ft_strjoin(char *str1, char *str2)
{
	size_t		i;
	size_t		j;
	char		*out;

	// Check the validity of str1
	if (!str1)
	{
		// If it's not validy, allocate memory to set \0 char
		str1 = (char *)malloc(sizeof(char) * 1);
		str1[0] = '\0';
	}
	// Check the validity of str2
	if (!str2)
		return (NULL);
	// Allocate memory to the output
	// Resulting in the size of str1 + str2 + 1
	out = (char *)malloc(sizeof(char) * (ft_len(str1) + ft_len(str2) + 1));
	// Check the memory allocation
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	// Fill out with the str1
	while (str1[i])
		out[j++] = str1[i++];
	i = 0;
	// Fill out with str2
	while (str2[i])
		out[j++] = str2[i++];
	// Set the terminator char to the end of out
	out[j] = '\0';
	// Free the allocated memory of str1
	free(str1);
	return (out);
}

/*This function reads a line of text from a file descriptor
and returns a string containing the line of text.
ssize_t signed size.
read(int fd, void *buf, size_t count) will return the
ssize_t of byte read from file descriptor:
-1 for error or the number of byte. count is the maximum
size of bytes read*/

char	*ft_line_allocation(int fd, char *str)
{
	char	*buff;
	ssize_t	dim;

	// Allocate memory to the buffer
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// Check the allocation
	if (!buff)
		return (NULL);
	dim = 1;
	// Traverse str while it's not \n and dim is not set to 0
	while (!(ft_strchr(str, '\n')) && dim > 0)
	{
		// Read the file 
		dim = read(fd, buff, BUFFER_SIZE);
		// If an error occurs
		if (dim == -1)
		{
			// Free the buffer and return null
			free(buff);
			return (NULL);
		}
		// Set the terminator to the end
		buff[dim] = '\0';
		// Apply strjoin to merge the previous str to buff
		str = ft_strjoin(str, buff);
	}
	// Free the memory
	free(buff);
	return (str);
}

/*This function extracts the next line of text from a string and returns
a new string containing the next line of text.*/

char	*ft_next_line(char *str)
{
	char	*new;
	int		i;

	i = 0;
	// Check the base case
	if (str[i] == 0)
		return (NULL);
	// Traverse str until it finds the new line marker or the end of it	
	while (str[i] && str[i] != '\n')
		i++;
	// When it find the end of the line, allocate memory to it + (\n and \0)
	new = (char *)malloc(sizeof(char) * (i + 2));
	// Check the memory allocation
	if (!new)
		return (NULL);
	i = 0;
	// Copy the characters of the original string to the new one until \n or the end
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	// If the next char is \n, copy it too
	if (str[i] == '\n')
	{
		new[i] = '\n';
		i++;
	}
	// set \0 to the end of the new str
	new[i] = '\0';
	return (new);
}

/*This function removes the next line of text from a string
and returns a new string containing the remaining text*/

char	*ft_rem_line(char *line)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_len(line) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (line[i])
		str[j++] = line[i++];
	str[j] = '\0';
	free(line);
	return (str);
}

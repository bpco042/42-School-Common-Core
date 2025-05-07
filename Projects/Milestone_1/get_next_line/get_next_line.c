/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c               		                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/23 15:47:34 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

//Function similar to ft_strlen
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

//Main function of gnl
char	*get_next_line(int fd)
{
	char		*rtn;
	static char	*str;

	// Check the validity of the buffer size and the file descriptor
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	// Read and store the content of the file inside str
	str = ft_line_allocation(fd, str);
	// Check the allocation
	if (!str)
		return (NULL);
	// Get the next line of the file
	rtn = ft_next_line(str);
	// If there's no more lines, free str and return null
	if (!rtn)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	// Remove the allocated line from the buffer
	str = ft_rem_line(str);
	return (rtn);
}
/*int	main(void)
{
	char	*s;
	int		i;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}
	i = 1;
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("line [%02d]: %s", i++, s);
		free(s);
	}
	close(fd);
	return (0);
}*/

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
#include "get_next_line_bonus.h"

/* nao funciona como bonus porque estou usando 4096 variaveis estaticas. preciso refatorar essa funcao, provavelente usando list*/
char	*get_next_line(int fd)
{
	char	*rtn;
	static char	*str[4096];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = ft_line_allocation(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	rtn = ft_next_line(str[fd]);
	str[fd] = ft_rem_line(str[fd]);
	return (rtn);
}
int	main(void)
{
	char	*s1 = NULL;
	char	*s2 = NULL;
	char	*s3 = NULL;
	int	fd1;
	int	fd2;
	int	fd3;
	int	line_nb = 1;

	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	fd3 = open("file3.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		perror("Error");
		return (1);
	}
	while (s1 != NULL || s2 != NULL || s3 != NULL || line_nb == 1)
	{
		if (s1 != NULL || line_nb == 1)
		{
			s1 = get_next_line(fd1);
			if (s1)
			{
				printf("file1 - line %d: %s", line_nb, s1);
				free(s1);
			}
		}
		if (s2 != NULL || line_nb == 1)
		{
			s2 = get_next_line(fd2);
			if (s2)
			{
				printf("file2 - line %d: %s", line_nb, s2);
				free(s2);
			}
		}
		if (s3 != NULL || line_nb == 1)
		{
			s3 = get_next_line(fd3);
			if (s3)
			{
				printf("file3 - line %d: %s", line_nb, s3);
				free(s3);
			}
		}
		line_nb++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
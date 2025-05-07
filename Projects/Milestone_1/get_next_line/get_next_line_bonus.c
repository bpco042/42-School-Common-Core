/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c         		                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/23 15:47:34 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

t_fd_list	*find_create_fd(t_fd_list **head, int fd)
{
	t_fd_list	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = malloc(sizeof(t_fd_list));
	if (!temp)
		return (NULL);
	temp->fd = fd;
	temp->buffer = NULL;
	temp->next = *head;
	*head = temp;
	return (temp);
}

void	remove_fd(t_fd_list **head, int fd)
{
	t_fd_list	*current;
	t_fd_list	*previous;

	current = *head;
	previous = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (previous)
				previous->next = current->next;
			else
				*head = current->next;
			free(current->buffer);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list;
	t_fd_list			*node;
	char				*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	node = find_create_fd(&fd_list, fd);
	if (!node)
		return (NULL);
	node->buffer = ft_line_allocation(fd, node->buffer);
	if (!node->buffer)
	{
		remove_fd(&fd_list, fd);
		return (NULL);
	}
	line = ft_next_line(node->buffer);
	node->buffer = ft_rem_line(node->buffer);
	if (!line)
		remove_fd(&fd_list, fd);
	return (line);
}
/*int	main(void)
{
	int		fd1 = open("file.txt", O_RDONLY);
	int		fd2 = open("file2.txt", O_RDONLY);
	int		fd3 = open("file3.txt", O_RDONLY);
	char	*line;
	int		i = 1;
	int		end1 = 0, end2 = 0, end3 = 0;

	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		perror("Erro ao abrir os arquivos");
		return (1);
	}

	while (!end1 || !end2 || !end3)
	{
		if (!end1)
		{
			line = get_next_line(fd1);
			if (line)
			{
				printf("fd1 - line [%02d]: %s", i, line);
				free(line);
			}
			else
				end1 = 1;
		}
		if (!end2)
		{
			line = get_next_line(fd2);
			if (line)
			{
				printf("fd2 - line [%02d]: %s", i, line);
				free(line);
			}
			else
				end2 = 1;
		}
		if (!end3)
		{
			line = get_next_line(fd3);
			if (line)
			{
				printf("fd3 - line [%02d]: %s", i, line);
				free(line);
			}
			else
				end3 = 1;
		}
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
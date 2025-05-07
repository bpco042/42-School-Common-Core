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

// Function similar to strlen
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
// Function to find a node. Else, create one.
t_fd_list	*find_create_fd(t_fd_list **head, int fd)
{
	t_fd_list	*temp;

	temp = *head;
	// Traverse the list to find the node
	while (temp)
	{
		if (temp->fd == fd)
			return (temp); // Found it, so return the node
		temp = temp->next;
	}
	// If the fd is not found, allocate memory to create a new one
	temp = malloc(sizeof(t_fd_list));
	if (!temp)
		return (NULL); // Return null in case of failure
	// Initialize the new node
	temp->fd = fd;
	temp->buffer = NULL;
	temp->next = *head;
	// Insert the new node at the beginning of the list
	*head = temp;
	return (temp);
}

// Remove the node from the list
void	remove_fd(t_fd_list **head, int fd)
{
	t_fd_list	*current;
	t_fd_list	*previous;

	current = *head;
	previous = NULL;

	// Traverse the list to find the fd node
	while (current)
	{
		// Connect the previous node to the next, removing the current one
		if (current->fd == fd)
		{
			if (previous)
				previous->next = current->next;
			else
				*head = current->next;
			// Free up the buffer and the node
			free(current->buffer);
			free(current);
			return ;
		}
		previous = current;
		current = current->next;
	}
}

// Main function of get_next_line
char	*get_next_line(int fd)
{
	static t_fd_list	*fd_list; // Static list that stores the fds
	t_fd_list			*node;
	char				*line;

	// Check the buffer size and the fd
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	// Search or create the node/fd
	node = find_create_fd(&fd_list, fd);
	if (!node)
		return (NULL);
	// Read the fd and store the content in the buffer
	node->buffer = ft_line_allocation(fd, node->buffer);
	if (!node->buffer)
	{
		// If the reading fails or ends, remove the node and return null
		remove_fd(&fd_list, fd);
		return (NULL);
	}
	// Extract the next line of the buffer
	line = ft_next_line(node->buffer);
	// Remove the extracted line from the buffer, updating the rest of the content
	node->buffer = ft_rem_line(node->buffer);
	// If no line was extracted or and error happened, remove the node
	if (!line)
		remove_fd(&fd_list, fd);
	return (line); // Return the line
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

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

char	*get_next_line(int fd)
{
	char		*rtn;
	static char	*str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_line_allocation(fd, str);
	if (!str)
		return (NULL);
	rtn = ft_next_line(str);
	str = ft_rem_line(str);
	return (rtn);
}
/*int	main(void)
{ão com `Valgrind`, c
		return (1);
	}
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break;
		printf("line %d: %s", line_nb, s);
		free(s);
		line_nb++;
	}
	close(fd);
	return (0);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruperei <bruperei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:20:18 by bruperei          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:41 by bruperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    void    *memory;

    if (size != 0 && (count * size) / size != count)
        return (NULL);
    memory = malloc(count * size);
    if (!memory)
        return (NULL);
    ft_bzero(memory, (count * size));
    return (memory);    
}
/*
int main() {
    int *arr;
    size_t count = 5;
    size_t size = sizeof(int);

    arr = ft_calloc(count, size);
    if (!arr) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (size_t i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}
*/
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
    
    // Check for overflow: if size is not zero (to avoid division by zero)
    // and (count * size) / size doesn't equal count, it means an overflow occurred    
    if (size != 0 && ((count * size) / size) != count)
        return (NULL);
    
    // Allocate memory to hold the requested data
    memory = malloc(count * size);
    
    // Check if the allocation was successful
    if (!memory)
        return (NULL);
    
    //Set all allocated memory to zero
    ft_bzero(memory, (count * size));
    // Returns a pointer to the allocated memory
    return (memory);    
}
/*Allocates memory and sets it's bytes to zero
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

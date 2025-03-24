#include <stdio.h>
#include "libft.h"

int main(void)
{
    char c = '7';

    if (ft_isalpha(c))  // Se for uma letra, ft_isalpha retorna 1
    {
        printf("É uma letra.\n");
        return 0;  // Retorna 0 se for uma letra
    }
    
    printf("Não é uma letra.\n");
    return 1;  // Retorna 1 se não for uma letra
}


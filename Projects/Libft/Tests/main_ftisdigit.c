#include <stdio.h>
#include "libft.h"

int main(void)
{
    int x = 'a';

    if (ft_isdigit(x))  // Se for um digito, retorna 1
    {
        printf("É um digito.\n");
        return 0;  // Retorna 0 se for uma letra
    }
    
    printf("Não é um digito.\n");
    return 1;  // Retorna 1 se não for uma letra
}

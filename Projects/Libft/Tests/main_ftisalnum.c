#include <stdio.h>
#include "libft.h"

int main(void)
{
    char c = 'a';

    if (ft_isalpha(c))  // Se for uma letra, ft_isalpha retorna 1
    {
        printf("É alfanumérico.\n");
        return 0;  // Retorna 0 se for uma letra
    }
    
    printf("Não é alfanumérico.\n");
    return 1;  // Retorna 1 se não for uma letra
}

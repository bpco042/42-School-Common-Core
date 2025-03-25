char *ft_strnstr(const char *str, const char *substr, int len)
{
    int i;
    int j;

    if (*substr == '\0')
        return ((char *)str);
    i = 0;
    while (str[i] && i < len)
    {
        j = 0;
        while (str[i + j] == substr[j] && str[i + j] && substr[j] && (i + j) < len)
            j++;
        if (substr[j] == '\0')
            return ((char *)&str[i]);
        i++;
    }
    return (0);
}

#include <stdio.h>

int main(void)
{
    char str[] = "Hello, World!";
    char substr[] = "World";
    char *result = ft_strnstr(str, substr, 9);
    
    if (result)
        printf("%s\n", result);
    else
        printf("(null)\n");

    return (0);
}

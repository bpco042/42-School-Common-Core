int ft_strlcpy(char *dst, const char *src, int size)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (src[j] != '\0')
        j++;
    if (size == 0)
        return (j);
    while (src[i] && i < size - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (j);
}
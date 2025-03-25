int ft_strlcat(char *dst, const char *src, int size)
{
    int i;
    int j;
    int k;

    i = 0;
    j = 0;
    k = 0;
    while (dst[i] != '\0')
        i++;
    while (src[j] != '\0')
        j++;
    if (size <= i)
        j += size;
    else
        j += i;
    while (src[k] && i + 1 < size)
    {
        dst[i] = src[k];
        i++;
        k++;
    }
    dst[i] = '\0';
    return (j);
}
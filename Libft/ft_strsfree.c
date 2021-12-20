void    ft_strsfree(char **str)
{
    size_t i;

    i = 0;
    if (str != NULL && *str != NULL)
    {
        while (str[i])
            free(str[i++]);
        free(str);
    }
}
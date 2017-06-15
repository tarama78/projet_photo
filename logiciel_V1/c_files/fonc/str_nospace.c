void str_nospace(char *str)
{
    int		i;
    int		j;
    char	copy[100];

    i = -1;
    j = 0;
    while (++i < (int)strlen(str))
    {
	if (str[i] != ' ' && str[i] != '\t')
	{
	    copy[j] = str[i];
	    j++;
	}
    }
    copy[j] = '\0';
    strcpy(str, copy);
}

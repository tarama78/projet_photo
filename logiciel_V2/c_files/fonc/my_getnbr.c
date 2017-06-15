int my_getnbr(char *str)
{
    int		nb;
    int		multipl;
    int		i;
    int		neg;

    nb = 0;
    multipl = 1;
    i = (int)strlen(str);
    neg = (str[0] == '-') ? (1) : (0);
    while (--i >= neg)
    {
	nb += (str[i] - 48) * multipl;
	multipl *= 10;
    }
    nb = (neg == 1) ? (-nb) : (nb);
    return (nb);
}

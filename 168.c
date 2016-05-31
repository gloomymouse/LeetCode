char* convertToTitle(int n)
{
    int len = 0;
    int tmp = n;
    while (tmp != 0)
    {
        len++;
        if (tmp % 26 == 0)
        {
            tmp -= 26;
        }
        tmp /= 26;
    }
    char *ret = (char *)malloc(len + 1);
    ret[len] = '\0';
    len--;
    tmp = n;
    while (tmp != 0)
    {
        ret[len] = (tmp % 26) + '@';
        if (ret[len] == '@')
        {
            ret[len] = 'Z';
            tmp -= 26;
        }
        len--;
        tmp /= 26;
    }
    return ret;
}

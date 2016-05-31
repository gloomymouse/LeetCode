int titleToNumber(char* s)
{
    int len = strlen(s);
    int ret = 0;
    for (int i = 0; i < len; i++)
    {
        ret = ret * 26 + s[i] - '@';
    }
    return ret;
}

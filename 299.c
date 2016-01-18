char* getHint(char* secret, char* guess)
{
    int len = strlen(secret);
    int num_s[10] = {0};
    int num_g[10] = {0};
    int a = 0, b = 0;
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (secret[i] == guess[i])
        {
            a++;
        }
        else
        {
            num_s[secret[i]-48]++;
            num_g[guess[i]-48]++;
        }
    }
    for (i = 0; i < 10; i++)
    {
        if (num_s[i] != 0 && num_g[i] != 0)
        {
            b += num_s[i]<num_g[i]?num_s[i]:num_g[i];
        }
    }
    char *ret = (char*)malloc(10);
    snprintf(ret, 9, "%d%c%d%c", a, 'A', b, 'B');
    return ret;
}

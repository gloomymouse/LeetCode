int countSubstrings(char* s) 
{
    int len = strlen(s);
    int ans = 0;
    int i = 0;
    int j = 0;
    
    if (1 >= len)
    {
        return len;
    }
    
    for (i = 0; i < len; i++)
    {
        for (j = 0; ((i - j >= 0) || (i + j < len)); j++)
        {
            if (s[i-j] == s[i+j])
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        if (len - 1 == i)
        {
            break;         
        }
        if (s[i] != s[i+1])
        {
            continue;    
        }
        for (j = 0; ((i - j >= 0) || (i + 1 + j < len)); j++)
        {
            if (s[i-j] == s[i+1+j])
            {
                ans++;
            }
            else
            {
                break;
            }
        }
    }
    
    return ans;
}

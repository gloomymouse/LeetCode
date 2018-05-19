char* reverseWords(char* s) 
{
    int i       = 0;
    int j       = 0;
    int len     = strlen(s);
    int wordlen = 0;
    char *ans   = (char *)malloc(len + 1);
    
    for (i = 0; i < len; i++)
    {
        if (s[i] != ' ')
        {
            wordlen++;
            continue;
        }
        
        for (j = 0; j < wordlen; j++)
        {
            ans[i-wordlen+j] = s[i-j-1];
        }
        ans[i] = ' ';
        wordlen = 0;        
    }

    for (j = 0; j < wordlen; j++)
    {
        ans[len-wordlen+j] = s[len-j-1];
    }
    
    ans[len] = '\0';
    return ans;
}

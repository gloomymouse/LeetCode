char* reverseString(char* s) 
{
    int i = 0;
    int len = strlen(s);
    char *ans = (char *)malloc(len + 1);
    
    for (i = 0; i < len; i++)
    {
        ans[i] = s[len-i-1];
    }
    ans[len] = '\0';
    
    return ans;
}

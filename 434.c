int countSegments(char* s)
{
    int ans = 0;
    int seg = 0;
    
    if (NULL == s)
    {
        return 0;
    }
    
    while (0 != *s)
    {
        if (' ' != *s && 0 == seg)
        {
            seg = 1;
            ans++;
        }
        else if (' ' == *s && 1 == seg)
        {
            seg = 0;
        }
        s++;
    }
    
    return ans;
}

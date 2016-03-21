bool isPalindrome(char* s)
{
    int pos = 0;
    int count = 0;
    
    while (s[pos+count] != '\0')
    {
        if (s[pos+count] < 48 
        || (s[pos+count] > 57 && s[pos+count] < 65) 
        || (s[pos+count] > 90 && s[pos+count] < 97) 
        || s[pos+count] > 122)
        {
            count++;
            continue;
        }
        else
        {
            s[pos] = s[pos+count];
            if (s[pos] >= 65 && s[pos] <= 90)
            {
                s[pos] += 32;
            }
            pos++;
        }
    }
    
    s[pos] = '\0';
    int len = strlen(s);
    char *reverse = (char *)malloc(len + 1);
    for (pos = 0; pos < len; pos++)
    {
        reverse[pos] = s[len-pos-1];
    }
    reverse[len] = '\0';
    //printf("%s %s %d", s, reverse, len);
    
    for (pos = 0; pos < len; pos++)
    {
        if (s[pos] != reverse[pos])
        {
            free(reverse);
            return false;
        }
    }
    free(reverse);
    return true;
}

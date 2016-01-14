bool isAnagram(char* s, char* t)
{
    int letters_s[26];
    int letters_t[26];
    memset(letters_s, 0, sizeof(letters_s));
    memset(letters_t, 0, sizeof(letters_t));
    
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_s == 0 && len_t == 0)
        return true;
    if (len_s != len_t)
        return false;
        
    int i = 0;
    for (i = 0; i < len_s; i++)
        letters_s[s[i]-97]++;
    
    for (i = 0; i < len_t; i++)
        letters_t[t[i]-97]++;

    for (i = 0; i < 26; i++)
    {
        if (letters_s[i] != letters_t[i])
            return false;
    }
    if (i == 26)
        return true;
}

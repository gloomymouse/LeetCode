bool detectCapitalUse(char* word) 
{
    int firstUp = 0;
    int upCnt   = 0;
    int len     = strlen(word);
    
    if (word[0] <= 'Z')
    {
        firstUp = 1;
    }
    
    while (*word != 0)
    {
        if (*word <= 'Z')
        {
            upCnt++;
        }
        word++;
    }
    
    return ((0 == upCnt) || (upCnt == len) || (1 == firstUp && 1 == upCnt));
}

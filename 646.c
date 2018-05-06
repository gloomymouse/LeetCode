int comp(const void*a,const void*b)
{
    return ((int*)a)[0]-((int*)b)[0];
}

int findLongestChain(int** pairs, int pairsRowSize, int pairsColSize) 
{
    int dp[1000] = {0};
    int maxlen = 0;
    
    qsort(pairs, pairsRowSize, sizeof(int)*2, comp);
       
    dp[0] = 1;
        
    for (int i = 1; i < pairsRowSize; i++)
    {
        maxlen = 0;
        for (int j = 0; j < i ; j++)
        {
            if (pairs[j][1] >= pairs[i][0])
            {
                continue;
            }
            if (maxlen < dp[j])
            {
                maxlen = dp[j];
            }
        }
        dp[i] = maxlen + 1;
    }
    
    return dp[pairsRowSize-1];
}

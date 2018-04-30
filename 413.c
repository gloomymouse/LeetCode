int numberOfArithmeticSlices(int* A, int ASize) 
{
    int ans = 0;
    int *dp;
    
    if (ASize <= 2)
    {
        return 0;
    }
    
    dp = (int *)malloc(sizeof(int)*ASize);
    memset(dp, 0, sizeof(int)*ASize);
    
    for (int i = 2; i < ASize; i++)
    {
        if (A[i-1] - A[i-2] == A[i] - A[i-1])
        {
            dp[i] = dp[i-1] + 1;
            ans += dp[i];
        }
    }
    
    free(dp);
    return ans;
}

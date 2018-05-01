int findLength(int* A, int ASize, int* B, int BSize) 
{
    int maxlen = 0;
    int dp[1001][1001] = {0};
    
    for (int i = 0; i < BSize; i++)
    {
        if (A[i] == B[0])
        {
            dp[i][0] = 1;
        }
    }
    
    for (int j = 0; j < BSize; j++)
    {
        if (A[0] == B[j])
        {
            dp[0][j] = 1;
        }
    }
    
    for (int i = 1; i < ASize; i++)
    {
        for (int j = 1; j < BSize; j++)
        {
            if (A[i] == B[j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                if (maxlen < dp[i][j])
                {
                    maxlen = dp[i][j];
                }
            }
        }
    }

    return maxlen;
}

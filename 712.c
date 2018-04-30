int minimumDeleteSum(char* s1, char* s2) 
{
    int sum = 0;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int dp[1001][1001] = {0};
    
    for (int j = 1; j <= len2; j++)
    {
        dp[0][j] = 0;
        sum += s2[j-1];
    }
    
    for (int i = 1; i <= len1; i++)
    {
        dp[i][0] = 0;
        sum += s1[i-1];
        for (int j = 1; j <= len2; j ++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + s1[i-1];
            }
            else
            {
                dp[i][j] = (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
            }
        }
    }
    
    sum -= (dp[len1][len2] * 2);
    return sum;
}
/* 类似最长公共子序列 */
/* dp存储的由 子序列长度 改为 子序列ascii值之和 */

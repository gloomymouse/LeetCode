int minPathSum(int** grid, int gridRowSize, int gridColSize) 
{
    int dp[200][200] = {0};
    
    dp[0][0] = grid[0][0];
    
    for (int j = 1; j < gridColSize; j++)
    {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    
    for (int i = 1; i < gridRowSize; i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int j = 1; j < gridColSize; j++)
        {
            dp[i][j] = (dp[i][j-1] < dp[i-1][j] ? dp[i][j-1] : dp[i-1][j]) + grid[i][j];
        }
    }

    return dp[gridRowSize-1][gridColSize-1];
}

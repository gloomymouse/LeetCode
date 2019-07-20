int numTrees(int n) {
    int* dp = (int*)malloc(sizeof(int) * (n+1));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int num = 0;
        for (int j = 0; j < i; j++) {
            num = num + dp[j] * dp[i-j-1];
        }
        dp[i] = num;
    }
    int ans = dp[n];
    free(dp);
    return ans;
}

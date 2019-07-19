int longestPalindromeSubseq(char * s){
    int dp[1001][1001];     // dp[i][j]为s[i]-s[j]字符串的最大回文子序列
    memset(dp, 0, sizeof(int) * 1001 * 1001);
    
    int max = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    for (int i = len - 1; i >= 0; i--) {    // 注意是从后往前
        for (int j = i + 1; j < len; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = (dp[i+1][j] > dp[i][j-1]) ? dp[i+1][j] : dp[i][j-1];
            }
        }
    }
    return dp[0][len-1];
}

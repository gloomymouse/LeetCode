bool divisorGame(int N){
    int i, j;
    bool dp[1001];
    
    dp[1] = false;
    for (i = 2; i <= N; i++) {
        dp[i] = false;
        for (j = 1; j <= i/2; j++) {
            // 如果dp[i-j]不能必胜，留给对方，则自己必胜
            if (i % j == 0 && dp[i-j] == false) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[N];
}

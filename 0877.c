#define MAX(a,b) ((a)>(b)?(a):(b))

bool stoneGame(int* piles, int pilesSize){
    // dp[i][j]记录的是piles[i]-piles[j]的石堆，先手可以赢对方多少颗，即最终最多比对手多多少
    int dp[500][500] = {0};
    
    for (int i = 0; i < pilesSize; i++) {
        dp[i][i] = piles[i];
    }
    
    for (int dis = 1; dis < pilesSize; dis++) {
        // 以piles[i]为最左边的一堆，piles[i+dis]为最右边的一堆
        for (int i = 0; i + dis < pilesSize; i++) {
            // 如果选择拿最左边一堆，则对手会选择dp[i+1]dp[i+dis]的最优解
            int select_left_max = dp[i][i] - dp[i+1][i+dis];
            // 如果选择拿最右边一堆，则对手会选择dp[i]dp[i+dis-1]的最优解
            int select_right_max = dp[i+dis][i+dis] - dp[i][i+dis-1];
            dp[i][i+dis] = MAX(select_left_max, select_right_max);
        }
    }
    
    if (dp[0][pilesSize-1] > 0) {
        return true;
    }
    return false;
}

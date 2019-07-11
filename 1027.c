#define LEN (2000)
#define DIFF_NUM (20001)
int dp[LEN][DIFF_NUM];  // dp[i][j]为：数字A[0]到A[i]的子数组中，差为j的数列的长度

int longestArithSeqLength(int* A, int ASize){
    int ans = 0;
    memset(dp, 0, sizeof(int)*LEN*DIFF_NUM);
    
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < i; j++) {
            int pos = 10000 + A[i] - A[j];
            dp[i][pos] = dp[j][pos] + 1;
            if (ans < dp[i][pos]) {
                ans = dp[i][pos];
            }
        }
    }
    
    return (ans + 1);
}

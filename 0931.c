#define MIN_OF_3(a,b,c) MIN(((a)<(b)?(a):(b)),(c))
#define MIN(a,b) ((a)<(b)?(a):(b))

int dp[100][100];   // A是正方形array，dp[i][j]为所有falling path走到A[i][j]位置的最小和

int minFallingPathSum(int** A, int ASize, int* AColSize){
    memset(dp, 0, sizeof(int)*100*100);
    for (int i = 0; i < ASize; i++) {
        dp[0][i] = A[0][i];
    }
    
    for (int i = 1; i < ASize; i++) {
        for (int j = 0; j < ASize; j++) {
            if (j == 0) {
                dp[i][j] = MIN(dp[i-1][0], dp[i-1][1]) + A[i][j];
            } else if (j == ASize - 1) {
                dp[i][j] = MIN(dp[i-1][ASize-2], dp[i-1][ASize-1]) + A[i][j];
            } else {
                dp[i][j] = MIN_OF_3(dp[i-1][j-1], dp[i-1][j], dp[i-1][j+1]) + A[i][j];
            }
        }
    }
    
    int min = dp[ASize-1][0];
    for (int i = 1; i < ASize; i++) {
        if (min > dp[ASize-1][i]) {
            min = dp[ASize-1][i];
        }
    }
    
    return min;
}

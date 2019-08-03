

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define ABS(a) (((a)>=0)?(a):(-(a)))

int** allCellsDistOrder(int R, int C, int r0, int c0, int* returnSize, int** returnColumnSizes){
    int num = R * C;
    int** ans = (int**)malloc(sizeof(int*)*num);
    int* colSizes = (int*)malloc(sizeof(int)*num);
    for (int i = 0; i < num; i++) {
        ans[i] = (int*)malloc(sizeof(int)*2);
        memset(ans[i], 0, sizeof(int)*2);
        colSizes[i] = 2;
    }
    /* 用队列做BFS */
    ans[0][0] = r0;
    ans[0][1] = c0;
    int head = 0;
    int tail = 1;
    int matrix[100][100];
    memset(matrix, 0, sizeof(int)*100*100);
    matrix[r0][c0] = 1;
    while (head < tail) {
        int r = ans[head][0];
        int c = ans[head][1];
        if (r != 0 && matrix[r-1][c] == 0) {
            ans[tail][0] = r - 1;
            ans[tail][1] = c;
            matrix[r-1][c] = 1;
            tail++;
        }
        if (c != 0 && matrix[r][c-1] == 0) {
            ans[tail][0] = r;
            ans[tail][1] = c - 1;
            matrix[r][c-1] = 1;
            tail++;
        }
        if (r != R - 1 && matrix[r+1][c] == 0) {
            ans[tail][0] = r + 1;
            ans[tail][1] = c;
            matrix[r+1][c] = 1;
            tail++;
        }
        if (c != C - 1 && matrix[r][c+1] == 0) {
            ans[tail][0] = r;
            ans[tail][1] = c + 1;
            matrix[r][c+1] = 1;
            tail++;
        }
        head++;
    }
    
    *returnSize = num;
    *returnColumnSizes = colSizes;
    return ans;
}

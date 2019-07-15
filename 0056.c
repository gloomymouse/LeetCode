/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int comp(const void* a,const void* b)
{
    return (*(int**)a)[0]-(*(int**)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    if (intervals == NULL) {
        *returnSize = 0;
        return NULL;
    }
    
    int n = 0;
    int** ans = (int**)malloc(sizeof(int*)*intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        ans[i] = (int*)malloc(sizeof(int)*2);
        memset(ans[i], 0, sizeof(int)*2);
    }
    
    qsort(intervals, intervalsSize, sizeof(intervals[0]), comp); 
    int i = 0;
    while (i < intervalsSize) {
        int left = intervals[i][0];
        int right = intervals[i][1];
        int j = i + 1;
        while (j < intervalsSize) {
            if (left == intervals[j][0]) {
                if (right < intervals[j][1]) {
                    right = intervals[j][1];
                }
                j++;
            } else {
                if (right >= intervals[j][0]) {
                    if (right < intervals[j][1]) {
                        right = intervals[j][1];
                    }
                    j++;
                } else {
                    break;
                }
            }
        }
        ans[n][0] = left;
        ans[n][1] = right;
        n++;
        i = j;
    }
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = 2;
    }
    return ans;
}

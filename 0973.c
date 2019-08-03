/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct Point {
    int index;
    int dist;
} Point;

int comp(const void* a, const void* b) {
    return (((Point*)a)->dist) - (((Point*)b)->dist);
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    int** ans = (int**)malloc(sizeof(int*)*K);
    int* colSizes = (int*)malloc(sizeof(int)*K);
    for (int i = 0; i < K; i++) {
        ans[i] = (int*)malloc(sizeof(int)*2);
        colSizes[i] = 2;
    }
    Point* dists = (Point*)malloc(sizeof(Point)*pointsSize);
    for (int i = 0; i < pointsSize; i++) {
        (dists[i]).dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        (dists[i]).index = i;
    }
    qsort(dists, pointsSize, sizeof(Point), comp);
    for (int i = 0; i < K; i++) {
        int j = (dists[i]).index;
        ans[i][0] = points[j][0];
        ans[i][1] = points[j][1];
    }
    free(dists);
    *returnSize = K;
    *returnColumnSizes = colSizes;
    return ans;
}

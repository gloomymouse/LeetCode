/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int adj[10000][3] = {0};
int adj_num[10000] = {0};

int get_type(int* ans, int my_adj[], int my_adj_num) {
    int type[5] = {0};
    int i = 0;
    for (i = 0; i < my_adj_num; i++) {
        type[ans[my_adj[i]]] = 1;
    }
    for (i = 1; i < 5; i++) {
        if (type[i] == 0) {
            break;
        }
    }
    return i;
}

int* gardenNoAdj(int N, int** paths, int pathsSize, int* pathsColSize, int* returnSize) {
    int* ans = (int*)malloc(sizeof(int)*N);
    memset(ans, 0, sizeof(int)*N);
    memset(adj_num, 0, sizeof(int)*10000);
    int i = 0;
    int j = 0;
    
    for (i = 0; i < pathsSize; i++) {
        adj[paths[i][0]-1][adj_num[paths[i][0]-1]] = paths[i][1] - 1;
        adj_num[paths[i][0]-1]++;
        adj[paths[i][1]-1][adj_num[paths[i][1]-1]] = paths[i][0] - 1;
        adj_num[paths[i][1]-1]++;
    }
    
    for (i = 0; i < N; i++) {
        ans[i] = get_type(ans, adj[i], adj_num[i]);
    }
    
    *returnSize = N;
    return ans;
}

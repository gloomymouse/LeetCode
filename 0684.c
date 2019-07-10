/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int adjmatrix[1000][1000];
int visited[1000];
int path[1000];

void DFS(int n, int start, int last_start, int *path_num, int* circle_node) {
    visited[start] = 1;
    
    // 记录选出的路径
    path[*path_num] = start + 1;
    (*path_num)++;
    
    int i = 0;
    for (i = 0; i < n; i++) {
        if (*circle_node != 0) {
            return;
        }

        if (i == last_start || i == start) {
            continue;
        }
        
        if (adjmatrix[start][i] == 1) {
            if (visited[i] == 0) {
                DFS(n, i, start, path_num, circle_node);
            } else {
                // 深度搜索，找到环路节点即退出
                *circle_node = i + 1;
                return;
            }
        }
    }
    
    if (*circle_node != 0) {
        return;
    }
    
    (*path_num)--;
    path[*path_num] = 0;
    return;
}

// 树增加一条边后，必定存在一个环，将环路上任意一条边断掉即可
int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*2);
    memset(adjmatrix, 0, sizeof(int)*1000*1000);
    
    int i = 0;
    for (i = 0; i < edgesSize; i++) {
        adjmatrix[edges[i][0]-1][edges[i][1]-1] = 1;
        adjmatrix[edges[i][1]-1][edges[i][0]-1] = 1;
    }

    int path_num = 0;
    int circle_node = 0;
    memset(visited, 0, sizeof(int)*1000);
    memset(path, 0, sizeof(int)*1000);
    DFS(edgesSize, 0, 0, &path_num, &circle_node);

    //printf("%d\n", circle_node);
    memset(visited, 0, sizeof(int)*1000);
    for (i = 0; i < path_num; i++) {
        if (path[i] == circle_node) {
            circle_node = 0;
        }
        if (circle_node != 0) {
            continue;
        }
        //printf("%d %d\n", path[i], path_num);
        // 标出环路上的所有节点
        visited[path[i]-1] = 1;
    }
    
    for (i = edgesSize - 1; i >= 0; i--) {
        // 根据题意，挑出在环路上的最后一条输入的边
        if (visited[edges[i][0]-1] == 1 && visited[edges[i][1]-1] == 1) {
            ans[0] = edges[i][0];
            ans[1] = edges[i][1];
            break;
        }
    }

    *returnSize = 2;
    return ans;
}

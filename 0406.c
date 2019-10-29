/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void reconstructSubQueue(int** people, int** ans, int pos, int size) {
    if (pos >= size) {
        return;
    }
    
    int real_pos = 0;
    int need_pos = people[pos][1];
    for (int i = 0; i < size; i++) {
        if (real_pos == need_pos && ans[i][0] == -1) {
            ans[i][0] = people[pos][0];
            ans[i][1] = people[pos][1];
            break;
        }
        if (ans[i][0] == -1 || ans[i][0] == people[pos][0]) {
            real_pos++;
        }
    }
    
    return reconstructSubQueue(people, ans, pos+1, size);
}


int cmp(const void* a, const void* b) {
    int* i = *(int**)a;
    int* j = *(int**)b; 
    return (i[0] == j[0]) ? (i[1] - j[1]) : (i[0] - j[0]);
}


int** reconstructQueue(int** people, int peopleSize, int* peopleColSize, int* returnSize, int** returnColumnSizes){
    int** ans = (int**)malloc(sizeof(int*) * peopleSize);
    int* column_sizes = (int*)malloc(sizeof(int) * peopleSize);
    for (int i = 0; i < peopleSize; i++) {
        ans[i] = (int*)malloc(sizeof(int) * 2);
        ans[i][0] = -1;
        column_sizes[i] = 2;
    }
    
    qsort(people, peopleSize, sizeof(int*), cmp);
    reconstructSubQueue(people, ans, 0, peopleSize);
    
    *returnSize = peopleSize;
    *returnColumnSizes = column_sizes;
    return ans;
}


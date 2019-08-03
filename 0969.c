/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void Reverse(int* A, int size) {
    int i = 0;
    int j = size - 1;
    while (i < j) {
        int tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
        i++;
        j--;
    }
    return;
}
int* pancakeSort(int* A, int ASize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*ASize*10);
    int size = 0;
    /* 找出最大的，经过两次翻转将最大的放到末尾，之后从前面再找次大的重复操作 */
    for (int i = ASize; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (i == A[j]) {
                Reverse(A, j + 1);
                ans[size++] = j + 1;
                Reverse(A, i);
                ans[size++] = i;
                break;
            }
        }
    }
    *returnSize = size;
    return ans;
}

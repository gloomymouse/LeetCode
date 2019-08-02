/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*arr1Size);
    memset(ans, 0, sizeof(int)*arr1Size);
    int cnts[1001];
    memset(cnts, 0, sizeof(int)*1001);
    
    /* 计数排序 O(n) */
    for (int i = 0; i < arr1Size; i++) {
        cnts[arr1[i]]++;
    }
    
    int num = 0;
    for (int i = 0; i < arr2Size; i++) {
        for (int j = 0; j < cnts[arr2[i]]; j++) {
            ans[num] = arr2[i];
            num++;
        }
        cnts[arr2[i]] = 0;
    }
    for (int i = 0; i <= 1000; i++) {
        if (cnts[i] == 0) {
            continue;   
        }
        for (int j = 0; j < cnts[i]; j++) {
            ans[num] = i;
            num++;
        }
    }
    
    *returnSize = num;
    return ans;
}

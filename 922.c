/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/* 申请新空间 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int* ans = (int*)malloc(sizeof(int)*ASize);
    int odd = 1;
    int even = 0;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            ans[even] = A[i];
            even += 2;
        } else {
            ans[odd] = A[i];
            odd += 2;
        }
    }
    
    *returnSize = ASize;
    return ans;
}

/* 不申请新空间 */
/*
int* sortArrayByParityII(int* A, int ASize, int* returnSize){
    int odd = 1;
    int even = 0;
    int scan_odd = 0;
    int swap_pos = -1;
    while (odd < ASize && even < ASize) {
        if (scan_odd == 0) {
            if (A[even] % 2 == 0) {
                even += 2;
            } else {
                if (swap_pos != -1) {
                    int tmp = A[swap_pos];
                    A[swap_pos] = A[even];
                    A[even] = tmp;
                    swap_pos = -1;
                    even += 2;
                } else {
                    swap_pos = even;
                    scan_odd = 1;
                }
            }
        } else {
            if (A[odd] % 2 == 1) {
                odd += 2;
            } else {
                if (swap_pos != -1) {
                    int tmp = A[swap_pos];
                    A[swap_pos] = A[odd];
                    A[odd] = tmp;
                    swap_pos = -1;
                    even += 2;
                } else {
                    swap_pos = odd;
                    scan_odd = 0;
                }
            } 
        }
    }
    
    *returnSize = ASize;
    return A;
}
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    
    int len = numsSize - k + 1;
    int* ans = (int*)malloc(sizeof(int) * len);
    
    int max = -2147483648;
    for (int j = 0; j < k; j++) {
        if (max < nums[j]) {
            max = nums[j];
        }
    }
    ans[0] = max;
    
    for (int i = 1; i + k <= numsSize; i++) {
        if (ans[i-1] < nums[i+k-1]) {
            ans[i] = nums[i+k-1];
            continue;
        }
        if (ans[i-1] > nums[i-1] && ans[i-1] > nums[i+k-1]) {
            ans[i] = ans[i-1];
            continue;
        }
        int max = -2147483648;
        for (int j = i; j < i + k; j++) {
            if (max < nums[j]) {
                max = nums[j];
            }
        }
        ans[i] = max;
    }
    
    *returnSize = len;
    return ans;
}

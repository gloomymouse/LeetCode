/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comp(const void* a, const void* b) {
    return (*(int*)a) - (*(int*)b);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1, nums1Size, sizeof(int), comp);
    qsort(nums2, nums2Size, sizeof(int), comp);
    int* ans = (int*)malloc(sizeof(int)*(nums1Size<nums2Size?nums1Size:nums2Size));
    int pos = -1;
    int i = 0;
    int j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            if (pos == -1 || ans[pos] != nums1[i]) {
                pos++;
                ans[pos] = nums1[i];
            }
            i++;
            j++;
        }
    }
    *returnSize = pos + 1;
    return ans;
}

void PrintSubsets(int* subsets, int k, int num_idx) {
    printf("%d| ", num_idx);
    for (int i = 0; i < k; i++) {
        printf("%d ", subsets[i]);
    }
    printf("\n");
}

bool CheckSubsets(int* subsets, int k, int ave) {
    for (int i = 0; i < k; i++) {
        if (ave != subsets[i]) {
            return false;
        }
    }
    return true;
}

bool PartitionKSubsets(int* nums, int nums_size, int k, int* subsets, int num_idx, int ave) {
    if (num_idx >= nums_size) {
        return CheckSubsets(subsets, k, ave);
    }
    int num = nums[num_idx];
    for (int i = 0; i < k; i++) {
        if (subsets[i] + num > ave) {
            continue;
        }
        subsets[i] += num;
        //PrintSubsets(subsets, k, num_idx);
        if (PartitionKSubsets(nums, nums_size, k, subsets, num_idx + 1, ave) == true) {
            return true;
        } else {
            subsets[i] -= num;
        }
    }
    return false;
}

int cmp(const void* a, const void* b)
{
    return *(int*)b - *(int*)a;
}

bool canPartitionKSubsets(int* nums, int numsSize, int k){
    int ave = 0;
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        ave += nums[i];
        if (max < nums[i]) {
            max = nums[i];
        }
    }
    if (ave % k != 0) {
        return false;
    }
    ave /= k;
    if (ave < max) {
        return false;
    }
    //printf("%d\n", ave);
    int* subsets = (int*)malloc(sizeof(int) * k);
    memset(subsets, 0, sizeof(int) * k);
    qsort(nums, numsSize, sizeof(int), cmp);
    bool res = PartitionKSubsets(nums, numsSize, k, subsets, 0, ave);
    free(subsets);
    return res;
}

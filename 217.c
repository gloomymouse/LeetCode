int cmp (const void *a , const void *b)
{
    return *(int *)a - *(int *)b; 
}

bool containsDuplicate(int* nums, int numsSize)
{
    if (numsSize == 0)
        return false;
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    while (--numsSize)
    {
        if (nums[numsSize] == nums[numsSize-1])
            return true;
    }
    return false;
}

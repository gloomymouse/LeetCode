int findMin(int* nums, int numsSize)
{
    int i = 0;
    for (i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] > nums[i+1])
            return nums[i+1];
    }
    if (i == numsSize -1 )
        return nums[0];
}

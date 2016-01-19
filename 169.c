int majorityElement(int* nums, int numsSize)
{
    int ret = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (ret == nums[i])
            count++;
        else
        {
            if (count == 0)
                ret = nums[i];
            else
                count--;
        }
    }
    return ret;
}

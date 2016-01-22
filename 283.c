void moveZeroes(int* nums, int numsSize)
{
    int i = 0;
    int tmp = 0;
    while (i < numsSize)
    {
        if (nums[i] == 0)
        {
            i++;
            continue;
        }
        if (tmp != i)
        {
            nums[tmp] = nums[i];
            nums[i] = 0;
        }
        tmp++;
        i++;
    }
}

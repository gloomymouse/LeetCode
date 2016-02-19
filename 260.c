/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
    *returnSize = 2;
    int *ret = (int*)malloc(sizeof(int)*(*returnSize));
    int i = 0;
    int xor_result = 0;
    for (i = 0; i < numsSize; i++)
    {
        xor_result ^= nums[i];      // 所求2个数的异或
    }
    int n = 0;
    while ((xor_result & 1) == 0)
    {
        xor_result >>= 1;           // 最右第一个为1的位，即所求2个数不同的位
        n++;
    }
    int tail_0 = 0;
    int tail_1 = 0;
    for (i = 0; i < numsSize; i++)
    {
        if ((nums[i] >> n & 1) == 0)
            tail_0 ^= nums[i];      // 该位为0的数
        else
            tail_1 ^= nums[i];      // 该位为1的数
    }
    ret[0] = tail_0;
    ret[1] = tail_1;
    return ret;
}

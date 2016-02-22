// 异或操作，即 mod 2
int singleNumber(int* nums, int numsSize)
{
    int len = 8 * sizeof(int);
    int ret = 0;
    for (int digit = 0; digit < len; digit++)
    {
        int sum = 0;
        for (int i = 0; i < numsSize; i++)
        {
            if(nums[i] & (1 << digit))  // 与(&)操作，逐个提取每一位的值
                sum++;
        }
        if(sum % 3)   // 若模3不为0，则出现次数不为3次的数该位为1
            ret = ret | (1 << digit);   // 或(|)操作，ret保持之前的位值不变，并与当前位相加
    }
    return ret;
}
/*
int singleNumber(int* nums, int numsSize)
{
    int len = 8 * sizeof(int);
    int *ternary = (int*)malloc(sizeof(int)*len);
    memset(ternary, 0, sizeof(ternary));
    int i = 0;
    int digit = 0;
    int ret = 0;
    for (i = 0; i < numsSize; i++)
    {
        for (digit = 0; digit < len; digit++)
        {   
            ternary[digit] = (ternary[digit] + (nums[i] >> digit & 1)) % 3;
        }
    }
    for (digit = 0; digit < len; digit++)
    {
        ret += ternary[digit] << digit;
    }
    return ret;
}
*/

/* piSum[i]为[nums[0],nums[i]]的最大子段和 */
int maxSubArray(int* nums, int numsSize) 
{    
    int iMaxSum = 0;
    int *piSum;
    
    piSum = (int *)malloc(sizeof(int)*numsSize);
    memset(piSum, 0, (sizeof(int)*numsSize));
    
    piSum[0] = nums[0];
    iMaxSum  = nums[0];
    
    for (int i = 1; i < numsSize; i++)
    {
        if (piSum[i-1] >= 0)
        {
            piSum[i] = piSum[i-1] + nums[i];
        }
        else
        {
            piSum[i] = nums[i];
        }
        
        if (iMaxSum < piSum[i])
        {
            iMaxSum = piSum[i];
        }
    }
    
    return iMaxSum;
}

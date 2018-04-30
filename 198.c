int rob(int* nums, int numsSize) 
{
    int iMax = 0;
    int *piMax;
    
    if (0 == numsSize)
    {
        return 0;
    }
    
    if (1 == numsSize)
    {
        return nums[0];
    }
    
    piMax = (int *)malloc(sizeof(int)*numsSize);
    piMax[0] = nums[0];
    piMax[1] = nums[1];
    piMax[2] = nums[0] + nums[2];
    
    for (int i = 3; i < numsSize; i++)
    {
        iMax = (piMax[i-3] > piMax[i-2]) ? piMax[i-3] : piMax[i-2];
        piMax[i] = iMax + nums[i];
    }   
    iMax = ((piMax[numsSize-2] > piMax[numsSize-1]) ? piMax[numsSize-2] : piMax[numsSize-1]);
    
    free(piMax); 
    return iMax;
}

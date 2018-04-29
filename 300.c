int lengthOfLIS(int* nums, int numsSize) 
{
    int iRet    = 1;
    int iMaxLen = 0;
    int *piLen;
    
    if (0 == numsSize)
    {
        return 0;
    }
    
    piLen = (int *)malloc(sizeof(int) * numsSize);
    
    memset(piLen, 0, (sizeof(int) * numsSize));
    piLen[0] = 1;
    
    for (int i = 1; i < numsSize; i++)
    {
        iMaxLen = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] >= nums[i])
            {
                continue;
            }
            
            if (piLen[j] > iMaxLen)
            {
                iMaxLen = piLen[j];
            }
        }
        piLen[i] = iMaxLen + 1;
        
        if (iRet < piLen[i])
        {
            iRet = piLen[i];
        }
    }
    
    free(piLen);
    return iRet;
}

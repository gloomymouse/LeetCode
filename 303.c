typedef struct 
{
    int *piNum;
    int *piSum;
    int iNumSize;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) 
{
    int iSum = 0;
    NumArray *pNumArray = (NumArray *)malloc(sizeof(NumArray));
    
    pNumArray->iNumSize = numsSize;
    pNumArray->piNum    = (int *)malloc(sizeof(int)*numsSize);
    pNumArray->piSum    = (int *)malloc(sizeof(int)*numsSize);
    
    for (int i = 0; i < numsSize; i++)
    {
        pNumArray->piNum[i] = nums[i];
        iSum += nums[i];
        pNumArray->piSum[i] = iSum;
    }
    
    return pNumArray;
}

int numArraySumRange(NumArray* obj, int i, int j) 
{
    if (0 == i)
    {
        return obj->piSum[j];
    }
    
    return (obj->piSum[j] - obj->piSum[i-1]);
}

void numArrayFree(NumArray* obj) 
{
    free(obj->piNum);
    free(obj->piSum);
    free(obj);
    return;
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */

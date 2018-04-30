/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) 
{
    int flag = 1;
    int *array;
    
    *returnSize = num + 1;
    array = (int *)malloc(sizeof(int)*(*returnSize));
    array[0] = 0;
        
    for (int i = 1; i <= num; i++)
    {
        if (i == flag * 2)
        {
            flag *= 2;
        }
        array[i] = array[i-flag] + 1;
    }
    
    return array;
}
/*二进制每多一位，就是在前面所有的个数上+1*/

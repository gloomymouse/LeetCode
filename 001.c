/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void*a,const void*b)
{
	return *(int*)a-*(int*)b;
}

int* twoSum(int* nums, int numsSize, int target) 
{
	int i = 0;
	int j = 0;
	int n = 0;
	int *array = (int *)malloc(sizeof(int)*numsSize);
	for (i=0; i<numsSize; i++)
		array[i] = nums[i];
	int *index = (int *)malloc(sizeof(int)*2);

	qsort(array, numsSize, sizeof(int), cmp);

	i = 0;
	j = numsSize - 1;
	while (1)
	{
		if (array[i] + array[j] == target)
			break;
		else if (array[i] + array[j] < target)
		{
			i++;
			continue;
		}
		else if (array[i] + array[j] > target)
		{
			j--;
			continue;
		}
	}
	
	n = 0;
	while (1)
	{
	    if (nums[n] == array[i] || nums[n] == array[j])
	    {
	        index[0] = n + 1;
	        break;
	    }
	    n++;
	}
	//printf("%d\n",n);
	n++;
	while (1)
	{
		if (nums[n] == array[i] || nums[n] == array[j])
		{
			index[1] = n + 1;
			break;
		}
			n++;
	}
	return index;
}

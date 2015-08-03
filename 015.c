// Cost Too Much RunTime!

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b)
{
	return *(int*)a-*(int*)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int pos = 0;
	int i = 0;
	int numsZero = 0;
	*returnSize = 0;
	if (numsSize < 3)
		return NULL;
	    
    while (i < numsSize)
	{
	    printf("%d ",nums[i]);
	    ++i;
	}
	i = 0;

	while (i < numsSize)
	{
		if (nums[i] == 0)
		{
			if (nums[i+1] == 0 && nums[i+2] == 0)
				++i;
			if (i == 0)
				++i;
			pos = i;
			break;
		}
		if (nums[i] < 0 && nums[i+1] > 0)
		{
			if (i == 0)
				++i;
			else if (i == numsSize - 1)
				--i;
			pos = i;
			break;
		}
		++i;
	}
    
	int** ret = NULL;
	ret = (int**)malloc(sizeof(int*)*(2048));
	for (i=0; i<(2048); i++)
	{
		ret[i] = (int*)malloc(sizeof(int)*3);
	}
	int n = 0;

	int left = 0, middle = pos, right = numsSize - 1;

	while (left <= pos)
	{
		if (left > 0 && nums[left] == nums[left-1])
		{
			++left;
			continue;
		}
		right = numsSize - 1;
		while (right >= pos)
		{
			if (right < numsSize - 1 && nums[right] == nums[right+1])
			{
				--right;
				continue;
			}
		    
			if (left == pos)
			    middle = pos + 1;
		    else
		        middle = pos;
		        
			if (nums[left] + nums[right] <= 0)
			{
				while (nums[left] + nums[middle] + nums[right] <= 0 && middle < right)
				{
					if (nums[left] + nums[middle] + nums[right] == 0)
					{
						if (n > 0 && ret[n-1][0] ==nums[left] && ret[n-1][1] == nums[middle] && ret[n-1][2] == nums[right])
						{
							++middle;
							continue;
						}
						ret[n][0] = nums[left];
						ret[n][1] = nums[middle];
						ret[n][2] = nums[right];
						++n;
						++(*returnSize);
					}
					++middle;
				}		
			}
			else if (nums[left] + nums[right] > 0)
			{
				while (nums[left] + nums[middle] + nums[right] >= 0 && middle > left)
				{
					if (nums[left] + nums[middle] + nums[right] == 0)
					{
						if (n > 0 && ret[n-1][0] ==nums[left] && ret[n-1][1] == nums[middle] && ret[n-1][2] == nums[right])
						{
							--middle;
							continue;
						}
						ret[n][0] = nums[left];
						ret[n][1] = nums[middle];
						ret[n][2] = nums[right];
						++n;
						++(*returnSize);
					}
					--middle;
				}
			}
			--right;
		}
		++left;
	}

    if (n == 0)
        return NULL;
        
	return ret;
}

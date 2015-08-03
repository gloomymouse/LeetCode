/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	int half = numsSize/2;
	int half_count = 0;
	int tmp = half;
	int start, end;
	
	*returnSize = 2;
	int* range = (int*)malloc(sizeof(int)*(*returnSize));
	range[0] = -1;
	range[1] = -1;

	if (half == 0 && nums[0] == target)
	{
		range[0] = 0;
		range[1] = 0;
	}
	
	while (half)
	{
		if (half == 1)
		{
			++half_count;
		}
		half = (half + 1) / 2;

		if (nums[tmp] < target)
		{
			tmp += half;
		}
		else if (nums[tmp] > target)
		{
			tmp -= half;
		}

		if (nums[tmp] == target)
		{
			start = tmp;
			range[0] = start;
			end = tmp;
			range[1] = end;
			while (1)
			{
				--start;
				if (nums[start] != nums[tmp] || start == -1)
				{
					range[0] = ++start;
					break;
				}
			}
			while (1)
			{
				++end;
				if (nums[end] != nums[tmp] || end == numsSize)
				{
					range[1] = --end;
					break;
				}
			}
			break;
		}
		if (half_count > 1)
		{
			break;
		}
	}

	return range;
}

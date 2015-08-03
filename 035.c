int searchInsert(int* nums, int numsSize, int target)
{
	int i = 0;

	if (nums[0] > target)
	{
		return 0;
	}

	for (i=0; i<numsSize; ++i)
	{
		if (nums[i] == target)
		{
			return i;
		}
		if (nums[i] < target && nums[i+1] > target)
		{
			return i+1;
		}
	}

	if (i == numsSize)
	{
		return numsSize;
	}
}

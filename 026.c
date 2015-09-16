int removeDuplicates(int* nums, int numsSize)
{
	int size = numsSize;
	int last = 0;
	int tmp = nums[0];
	int i;

	for (i=1; i<numsSize; ++i)
	{
		if (tmp == nums[i])
		{
			size--;
		}
		else
		{
			tmp = nums[i];
			nums[++last] = tmp;
		}
	}
	return size;
}

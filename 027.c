int removeElement(int* nums, int numsSize, int val)
{
	int size = numsSize;
	int i = 0;

	while (i != size)
	{
		if (nums[i] == val)
		{
			nums[i] = nums[--size];
		}
		else
		    i++;
	}
	return size;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int ans;
	int i;
	
	for (i=digitsSize-1; i>=0; --i)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
		}
		else
		{
			digits[i]++;
			break;
		}
	}
	if (digits[0] > 0)
	{
		*returnSize = digitsSize;
		return digits;
	}
	else
	{
		*returnSize = digitsSize + 1;
		int* ans = (int*)malloc(sizeof(int)*(*returnSize));
		ans[0] = 1;
		for (i=0; i<digitsSize; ++i)
		{
			ans[i+1] = digits[i];
		}
		return ans;
	}
}

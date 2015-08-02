/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize)
{
	char* letters[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	int len = strlen(digits);
	int i = 0, n =0;

	int* index = (int*)malloc(sizeof(int)*len);
	for (i=0; i<len; ++i)
		index[i] = 0;
	int* num = (int*)malloc(sizeof(int)*10);
	for (i=0; i<10; ++i)
		num[i] = strlen(letters[i]);

	if (len == 0)
		return NULL;

	*returnSize = 1;
	for (i=0; i<len; ++i)
	{
		*returnSize *= num[(int)(digits[i])-(int)('0')];
	}

	char** ret = (char**)malloc(sizeof(char*)*(*returnSize));
	for (i=0; i<(*returnSize); ++i)
	{
		ret[i] = (char*)malloc(len);
	}

	for (i=0; i<(*returnSize); ++i)
	{
		n = 0;
		while (n < len)
		{
			ret[i][n] = letters[(int)(digits[n])-(int)('0')][index[n]];
			++n;
		}
		ret[i][n] = '\0';
		while (n)
		{
			--n;
			++index[n];
			if (index[n] == num[(int)(digits[n])-(int)('0')])
			{
				index[n] = 0;
				continue;
			}
			else
				break;
		}
	}

	return ret;
}

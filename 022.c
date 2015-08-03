/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

int par(char** retstr, char* str, int n, int len, int open, int pos, int flag, char ch)
{
	if (ch == '(' && n == 0)
		return flag;
	if (ch == ')' && open == 0)
		return flag;

	*(str+pos) = ch;
	++pos;

	if (ch == '(')
	{
		--n;
		++open;
	}
	if (ch == ')')
	{
		--open;
	}
	if (n == 0 && open == 0)
	{
		*(str+pos) = '\0';
		strcpy(retstr[flag], str);
		++flag;
		return flag;
	}

	flag = par(retstr, str, n, len, open, pos, flag, '(');
	flag = par(retstr, str, n, len, open, pos, flag, ')');
	return flag;
}

char** generateParenthesis(int n, int* returnSize)
{
	char* str = (char*)malloc(n*2);
	int open = 0;
	int pos = 0;
	int flag = 0;
	char** ret = (char**)malloc(sizeof(char*)*2048);
	for (int i=0; i<2048; ++i)
	{
		ret[i] = (char*)malloc(n*2+1);
	}

	flag = par(ret, str, n, n, open, pos, flag, '(');
	*returnSize = flag;

	return ret;
}

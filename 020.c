bool isValid(char* s)
{
	int len = strlen(s);
	int* stack = (int*)malloc(sizeof(int)*len);
	int top = -1;
	for (int i=0; i<len; ++i)
	{
		if (s[i] == '(')
		{
			stack[++top] = 0;
		}
		else if (s[i] == '[')
		{
			stack[++top] = 1;
		}
		else if (s[i] == '{')
		{
			stack[++top] = 2;
		}
		else
		{
			if (top == -1)
			{
				return 0;
			}
			else if (s[i] == ')' && stack[top] == 0)
			{
				--top;
			}
			else if (s[i] == ']' && stack[top] == 1)
			{
				--top;
			}
			else if (s[i] == '}' && stack[top] == 2)
			{
				--top;
			}
			else
			{
				return 0;
			}
		}
	}
	if (top == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

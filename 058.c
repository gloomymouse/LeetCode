int lengthOfLastWord(char* s)
{
	int len = strlen(s);
	int ans = 0;
	for (int i=len-1; i>=0; --i)
	{
		if (s[i] == ' ')
			--len;
		else
			break;
	}
	for (int i=len-1; i>=0; --i)
	{
		if (s[i] != ' ')
		{
			ans++;
		}
		else
		{
			return ans;
		}
	}
	return ans;
}

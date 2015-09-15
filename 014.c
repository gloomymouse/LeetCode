char* longestCommonPrefix(char** strs, int strsSize)
{
	if (strsSize == 0)
	{
		return "";
	}
	if (strsSize == 1)
	{
		return strs[0];
	}

	
	int i, j, n=0;
	int len = strlen(strs[0]);
	char c;

	if (len == 0)
	{
		return "";
	}

	for (i=0; i<strsSize; ++i)
	{
		if (strlen(strs[i]) < len)
		{
			len = strlen(strs[i]);
			n = i;
		}
	}
	char* prefix = (char*)malloc(len);
	prefix[0] = '\0';
	
	i = 0;
	
	while (strs[n][i] != '\0')
	{
		c = strs[n][i];
		for (j=0; j<strsSize; ++j)
		{
			if (c != strs[j][i])
			{
			    prefix[i] = '\0';
				return prefix;
			}
		}
		prefix[i] = c;
		++i;
	}
	prefix[i] = '\0';
	return prefix;
}

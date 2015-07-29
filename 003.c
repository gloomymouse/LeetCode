int lengthOfLongestSubstring(char* s)
{
	int len = strlen(s);
	int sublen = 0;
	int tmplen = 0;
	int pos[126-32+1];
	int tmppos = 0;
	int i = 0;
	for (i=0; i<(126-32+1); i++)
		pos[i] = -1;

	i = 0;
	while (i < len)
	{
		if (pos[(int)s[i]-32] == -1)
		{
			pos[(int)s[i]-32] = i;
			if (sublen == 0)
				tmplen++;
			else
			{
				tmplen = i - tmppos;
				if (sublen < tmplen)
					sublen = tmplen;
			}
		}
		else
		{
			if (sublen == 0)
				sublen = tmplen;
			if (tmppos < pos[(int)s[i]-32])
				tmppos = pos[(int)s[i]-32];
			tmplen = i - tmppos;
			if (sublen < tmplen)
				sublen = tmplen;
			pos[(int)s[i]-32] = i;
		}
		i++;
	}
	
	if (sublen == 0)
		sublen = tmplen;

	return sublen;
}

char* longestPalindrome(char* s)
{
	char* substr = (char*)malloc(sizeof(char)*1000);
	int slen = strlen(s);
	int plen = 0;
	int maxplen = 0;
	int i = 0;
	int left = 0, right = 0;

	if (slen == 1)
		return s;

	while (i < slen - 1)
	{
		left = i - 1;
		right = i + 1;
		plen = 1;
		while (left >= 0 && right < slen && s[left] == s[right])
		{
			plen = plen + 2;
			left--;
			right++;
		}
		if (maxplen < plen)
		{
			maxplen = plen;
			strncpy(substr, s+left+1, plen);	// !!!!!!!!!
			substr[plen] = '\0';				// !!!!!!!!!
		}

		if (s[i] == s[i+1])
		{
			left = i-1;
			right = i + 2;
			plen = 2;
			while (left >= 0 && right < slen && s[left] == s[right])
			{
				plen = plen + 2;
				left--;
				right++;
			}
			if (maxplen < plen)
			{
				maxplen = plen;
				strncpy(substr, s+left+1, plen);	// !!!!!!!!!
				substr[plen] = '\0';				// !!!!!!!!!
			}
		}

		i++;
	}

	return substr;
}

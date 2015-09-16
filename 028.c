int strStr(char* haystack, char* needle)
{
	int i=0, pos;
	int hlen = strlen(haystack);
	int nlen = strlen(needle);
	
	if (nlen == 0)
	{
		return 0;
	}

	for (pos=0; pos<hlen; ++pos)
	{
		if (hlen - pos < nlen)
		{
			return -1;
		}

		if (haystack[pos] != needle[0])
		{
			continue;
		}
		else
		{
			i = 0;
			while (i != nlen)
			{
				if (haystack[pos+i] == needle[i])
				{
					i++;
				}
				else 
					break;
			}
			if (i == nlen)
			{
				return pos;
			}
		}
	}
	return -1;
}

/*
*** "Runtime" need to be improved ***
*/
bool isMatch(char* s, char* p)
{
	int slen = strlen(s);
	int plen = strlen(p);
	int i = 0;
	int j = 0;
	while (i < slen && j < plen)
	{
		if (p[j] != '.' && p[j] != '*' && p[j+1] != '*')
		{
			if (p[j] == s[i])
			{
				i++;
				j++;
				continue;
			}
			else
				break;
		}
		if (p[j] == '.' && p[j+1] != '*')
		{
			i++;
			j++;
			continue;
		}
		if (p[j] != '.' && p[j] != '*' && p[j+1] == '*')
		{
			if (p[j] == s[i])
			{
				char* spart = (char*)malloc(slen+1);
				strncpy(spart, s+i, slen-i);
				spart[slen-i] = '\0';

				char* ppart = (char*)malloc(plen+1);
				strncpy(ppart, p+j+2, plen-j-2);
				ppart[plen-j-2] = '\0';

				if (isMatch(spart, ppart) == true)
				{	free(spart);
					free(ppart);
					return true;
				}
				else
				{
					free(spart);
					free(ppart);
					i++;
					continue;
				}
			}
			else
			{
				j = j + 2;
				continue;
			}
		}
		if (p[j] == '.' && p[j+1] == '*')
		{
			char* spart = (char*)malloc(slen+1);
			strncpy(spart, s+i, slen-i);
			spart[slen-i] = '\0';

			char* ppart = (char*)malloc(plen+1);
			strncpy(ppart, p+j+2, plen-j-2);
			ppart[plen-j-2] = '\0';

			if (isMatch(spart, ppart) == true)
			{
				free(spart);
				free(ppart);
				return true;
			}
			else
			{
				free(spart);
				free(ppart);
				i++;
				continue;
			}
		}
	}
	if (i == slen)
	{
		while (1)
		{
			if (p[j+1] == '*')
			{
				j = j + 2;
				if (j == plen)
					break;
				else
					continue;
			}
			else
				break;
		}
	}
	if (i == slen && j == plen)
		return true;
	else
		return false;
}

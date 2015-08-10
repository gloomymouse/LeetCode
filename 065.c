#define IS_NUM(a) ((a>=48&&a<=57)?1:0)
bool isNumber(char* s)
{
	int len = strlen(s);
	int i = 0;
	int beg = 0;
	int point = 0;
	int space = 0;
	int e = 0;
	int num_after_e = 0;
	int num = 0;
	int pn = 0;

	while (i < len)
	{
		if (beg == 0)
		{
			if (IS_NUM(s[i]))
			{
				++num;
				++beg;
				++i;
				continue;
			}
			else if (s[i] == ' ')
			{
				++i;
				continue;
			}
			else if (s[i] == '.')
			{
				++beg;
				++point;
				++i;
				continue;
			}
			else if (s[i] == '-' || s[i] == '+')
			{
				++beg;
				++pn;
				++i;
				continue;
			}
			else
			{
				return false;
			}
		}

		if (beg == 1)
		{
			if (s[i] == '.')
			{
				if (point == 0 && e == 0 && space == 0)
				{
					++point;
					++i;
					continue;
				}
				else
				{
					return false;
				}
			}
			if (s[i] == ' ')
			{
				if (space == 0)
				{
					++space;
				}
				++i;
				continue;
			}
			if (s[i] == 'e')
			{
				if (e == 0 && num > 0)
				{
					++e;
					++i;
					continue;
				}
				else
				{
					return false;
				}
			}
			else if (s[i] == '-' || s[i] == '+')
			{
				if (e == 0 || pn > 1)
				{
					return false;
				}
				++pn;
				++i;
				continue;
			}
			if (IS_NUM(s[i]))
			{
				++num;
				if (space == 1)
				{
					return false;
				}
				if (e == 1)
				{
					++num_after_e;
				}
				++i;
				continue;
			}
			else
			{
				return false;
			}
		}
	}

	if (i == len)
	{
		if (e > 0 && num_after_e == 0)
		{
			return false;
		}
		else if (s[i-1] == ' ' && num > 0)
		{
			return true;
		}
		else if (IS_NUM(s[i-1]))
		{
			return true;
		}
		else if (s[i-1] == '.' && num == 0)
		{
			return false;
		}
		else if (s[i-1] == '.' && num > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

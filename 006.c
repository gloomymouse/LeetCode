char* convert(char* s, int numRows) 
{
    int num = strlen(s);
	if (num == 0 || numRows == 1)
        return s;

    char* sFinal;
    sFinal = (char*)malloc(num + 1);

    int index;
	int i = 0;
    int n = 0;

	for (i=0; i<numRows; i++)
	{
		index = i;
		if (index >= num)
			break;
		while (1)
		{		
			if (i != numRows - 1)
			{
				sFinal[n] = s[index];
				n++;
				index = index + (numRows - 1 - i) * 2;
				if (index >= num)
					break;
			}
		
			if(i != 0 )
			{
				sFinal[n] = s[index];
				n++;
				index = index + i * 2;
				if (index >= num)
					break;
			}
		}
	}
	sFinal[n] = '\0';

	return sFinal;
}


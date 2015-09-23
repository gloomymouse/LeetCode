bool isValidSudoku(char** board, int boardRowSize, int boardColSize)
{
	int nums[9] = {0,0,0,0,0,0,0,0,0};
	int i, j;
	int n, m;
	for (i=0; i<9; ++i)
	{
		for (j=0; j<9; ++j)
		{
			if (board[i][j] == '.')
			{
				continue;
			}
			if (nums[board[i][j] - '1'] == 0)	// [0~8], NOT [nums[i][j]- '0']
			{
				nums[board[i][j] - '1'] = 1;
			}
			else if (nums[board[i][j] - '1'] == 1)
			{
				return false;
			}
		}
		for (j=0; j<9; ++j)
		{
			nums[j] = 0;
		}
	}
	for (i=0; i<9; ++i)
	{
		for (j=0; j<9; ++j)
		{
			if (board[j][i] == '.')
			{
				continue;
			}
			if (nums[board[j][i] - '1'] == 0)
			{
				nums[board[j][i] - '1'] = 1;
			}
			else if (nums[board[j][i] - '1'] == 1)
			{
				return false;
			}
		}
		for (j=0; j<9; ++j)
		{
			nums[j] = 0;
		}
	}
	for (i=0; i<3; ++i)
	{
		for (j=0; j<3; ++j)
		{
			for (m=0; m<3; ++m)
			{
				for (n=0; n<3; ++n)
				{
					if (board[i*3+m][j*3+n] == '.')
					{
						continue;
					}
					if (nums[board[i*3+m][j*3+n] - '1'] == 0)
					{
						nums[board[i*3+m][j*3+n] - '1'] = 1;
					}
					else if (nums[board[i*3+m][j*3+n] - '1'] == 1)
					{
						return false;
					}
				}
			}
			for (n=0; n<9; ++n)
			{
				nums[n] = 0;
			}
		}
	}
	return true;
}

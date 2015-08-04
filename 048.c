void rotate(int** matrix, int matrixRowSize, int matrixColSize)
{
    float r = ( matrixRowSize - 1.0 ) / 2.0;
	int n = matrixRowSize - 1;
	int tmp = 0;
	int i = 0, j = 0;

	while (i <= r)		// 有“=”， 平移坐标后，旋转轴上的点
	{
		j = 0;
		while (j < r)	// 没有“=”， 避免轴上的点旋转多次
		{
			tmp = matrix[i][j];
			matrix[i][j]     = matrix[n-j][i];
			matrix[n-j][i]   = matrix[n-i][n-j];
			matrix[n-i][n-j] = matrix[j][n-i];
			matrix[j][n-i]   = tmp;
			++j;
		}
		++i;
	}
}

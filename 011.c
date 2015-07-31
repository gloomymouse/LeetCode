#define min(x,y) (x<y?x:y)
#define max(x,y) (x>y?x:y)
int maxArea(int* height, int heightSize)
{
	int i = 0, j = heightSize - 1;
	int area = 0;
	int tmp = 0;
	while (i < j)
	{
		tmp = min(height[i], height[j]) * (j - i);
		area = max(area, tmp);
		if (height[i] < height[j])
			i++;
		else
			j--;
	}
	return area;
}

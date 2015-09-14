bool isPalindrome(int x)
{
	int tmp = x;
	int y = 0;
	if (x > 2147483647 || x < 0)
	{
		return 0;
	}
	while (tmp)
	{
		y = y * 10 + tmp % 10;
		tmp /= 10;
	}
	if (x == y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int reverse(int x)
{
	int y = 0;

	do{
		if (x > 0 && y > (INT_MAX-x%10)/10)
			return 0;
		if (x < 0 && y < (INT_MIN-x%10)/10)
			return 0;
		y = y * 10 + x%10;
		x = x / 10;
	}
	while (x);

	return y;
}

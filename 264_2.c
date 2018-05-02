int nthUglyNumber(int n) 
{
    int *num;
    int i2  = 0;
    int i3  = 0;
    int i5  = 0;
    int tmp = 0;
    
    if (0 == n)
    {
        return 0;
    }
    
    num = (int *)malloc(sizeof(int)*n);
    memset(num, 0, sizeof(int)*n);
    
    num[0] = 1; 
    for (int i = 1; i < n; i++)
    {
        tmp = (num[i2]*2 < num[i3]*3 ? num[i2]*2 : num[i3]*3);
        tmp = (tmp < num[i5]*5 ? tmp : num[i5]*5);
        num[i] = tmp;
        if (tmp == num[i2]*2)
        {
            i2++;
        }
        if (tmp == num[i3]*3)
        {
            i3++;
        }
        if (tmp == num[i5]*5)
        {
            i5++;
        }
    }
    
    tmp = num[n-1];
    free(num);
    return tmp;
}

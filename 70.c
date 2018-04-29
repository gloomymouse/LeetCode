int climbStairs(int n) 
{
    int a = 0;
    int b = 0;
    int step = 0;
    
    if (2 >= n)
    {
        return n;
    }
    
    a = 1;
    b = 2;
    for (int i = 2; i < n; i++)
    {
        step = a + b;
        a = b;
        b = step;
    }
    
    return step;
}

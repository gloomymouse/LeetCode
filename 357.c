int countNumbersWithUniqueDigits(int n) 
{
    int num = 0;
    int ans = 1;    // 0单独计算
    
    n = n < 10 ? n : 10;
    
    for (int i = 0; i < n; i++)
    {
        num = 9;
        for (int j = 0; j < i; j++)
        {
            num *= (9 - j);
        }
        ans += num;
    }
    
    return ans;
}

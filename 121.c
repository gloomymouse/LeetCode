int maxProfit(int* prices, int pricesSize) 
{
    int iRet        = 0;
    int iMaxProfit  = 0;
    int iMinPrice   = 0;
    
    if (1 >= pricesSize)
    {
        return 0;
    }

    iMinPrice = prices[0];
    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i] < iMinPrice)
        {
            iMinPrice = prices[i];
            continue;
        }
        
        if (iMaxProfit < prices[i] - iMinPrice)
        {
            iMaxProfit = prices[i] - iMinPrice;
        }
    }
    
    return iMaxProfit;
}

/* cost more time */
int maxProfit(int* prices, int pricesSize) 
{
    int iRet        = 0;
    int iMaxProfit  = 0;
    int *piProfit;
    
    if (1 >= pricesSize)
    {
        return 0;
    }
    
    piProfit = (int *)malloc(sizeof(int) * pricesSize);
    memset(piProfit, 0, (sizeof(int) * pricesSize));
    
    for (int i = 1; i < pricesSize; i++)
    {
        iMaxProfit = 0;
        for (int j = 0; j < i; j++)
        {
            if (prices[j] < prices[i])
            {
                if (iMaxProfit < (prices[i] - prices[j]))
                {
                    iMaxProfit = (prices[i] - prices[j]);
                    piProfit[i] = piProfit[j] + iMaxProfit;
                }
            }
        }
        
        if (iRet < piProfit[i])
        {
            iRet = piProfit[i];
        }
    }
    
    return iRet;
}

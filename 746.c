int minCostClimbingStairs(int* cost, int costSize) 
{
    int iRet                = 0;
    int iMinCost            = 0;
    int iTotalCost[1000]    = {0};
    
    iTotalCost[0] = cost[0];
    iTotalCost[1] = cost[1];
    
    for (int i = 2; i < costSize; i++)
    {
        iMinCost = (iTotalCost[i-2] < iTotalCost[i-1]) \
                    ? iTotalCost[i-2] : iTotalCost[i-1];
        iTotalCost[i] = iMinCost + cost[i];
    }
    
    iRet = (iTotalCost[costSize-2] < iTotalCost[costSize-1]) \
            ? iTotalCost[costSize-2] : iTotalCost[costSize-1];
    
    return iRet;
}

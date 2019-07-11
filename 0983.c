#define MIN_OF_3(a,b,c) MIN(((a)<(b)?(a):(b)),(c))
#define MIN(a,b) ((a)<(b)?(a):(b))

int mincostTickets(int* days, int daysSize, int* costs, int costsSize)
{
    int dp[366] = {0};  // dp[i]为第1~i天的票价和最小值
    int day = 1;

    for (int i = 0; i < daysSize; i++) {
        while (day < days[i]) {
            dp[day] = dp[day-1];
            day++;
        }
        
        dp[day] = dp[day-1] + costs[0];
        
        int last_day = (day >= 7) ? (day - 7) : 0;
        dp[day] = MIN(dp[day], dp[last_day] + costs[1]);

        last_day = (day >= 30) ? (day - 30) : 0;
        dp[day] = MIN(dp[day], dp[last_day] + costs[2]);
        
        day++;
    }
    
    return dp[days[daysSize-1]];
}

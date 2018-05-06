int maxProfit(int* prices, int pricesSize, int fee) 
{
    int cash_before_buy = 0;
    int cash_no_stock   = 0;
    int cash_after_buy  = 0;
    int cash_and_stock  = 0;
    int cash_after_sell = 0;
    
    cash_no_stock  = 0;
    cash_and_stock = -prices[0];
    
    for (int i = 1; i < pricesSize; i++)
    {
        cash_before_buy = cash_no_stock;
        
        cash_after_sell = cash_and_stock + prices[i] - fee;
        cash_no_stock   = cash_no_stock > cash_after_sell ? cash_no_stock : cash_after_sell;
        
        cash_after_buy  = cash_before_buy - prices[i];
        cash_and_stock  = cash_and_stock > cash_after_buy ? cash_and_stock : cash_after_buy;
    }
    
    return cash_no_stock;
}

/*
The solution maintains two states:

s0 = profit having no stock
s1 = profit having 1 stock
The code iterates through the stock prices, and updates s0, s1 respectively. The run time is O(n).

update s0 by selling the stock from s1, so s0 = max(s0, s1+p);
update s1 by buying the stock from s0, so s1 = max(s1, s0-p-fee);
*/

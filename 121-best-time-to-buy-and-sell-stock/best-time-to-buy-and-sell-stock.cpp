class Solution {
public:
    int maxProfit(vector<int>& prices) {

    /*
       int min_price = INT_MAX;
       int max_profit = 0;

       for (int p: prices)
       {
          if (p < min_price)
            min_price = p;
          else
            max_profit = max(max_profit, (p-min_price));
       }

       return maxprofit;
       */


       int n = prices.size();
       int maxProfit = 0;
       int minPrice = INT_MAX;
       // 不能 一次循环 直接找出 minPrice  与 maxPrice, 因为 有 时序关系在 控制着, 
       // 只能变计算 max profit, 边前进

       for (int i = 1; i < n; i++)
       {
          minPrice = min(minPrice, prices[i-1]);

          if (prices[i] > minPrice)
            maxProfit = max(maxProfit, (prices[i] - minPrice));
       }

       return maxProfit;

       /*
       // Time Limit Exceeded

       int n = prices.size();
       int maxProfit = 0;
       int minPrice = INT_MAX;
       for (int i = 0; i < n; i++)
       {
          minPrice = min(minPrice, prices[i]);
          for (int j = i + 1; j < n; j++)
          {
              if (prices[j] > minPrice)
                maxProfit = max(maxProfit, (prices[j]-minPrice));
          }
       }
 
       return maxProfit;
       */

    };
   
};
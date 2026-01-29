
class Solution {
public:
    int maxProfit(vector<int>& prices) {


       int n = prices.size();
       int maxProfit = 0;
       int minPrice = INT_MAX;
       // 不能 一次循环 直接找出 minPrice  与 maxPrice, 因为 有 时序关系在 控制着, 
       // 只能边计算 max profit, 边前进

       for (int i = 1; i < n; i++)
       {
          minPrice = min(minPrice, prices[i-1]);

          if (prices[i] > minPrice)
            maxProfit = max(maxProfit, (prices[i] - minPrice));
       }

       return maxProfit;

    };
   
};

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {

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
    }; 
};
*/

/*
class Solution {
public:
     //Greedy（贪心）解法
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // 到目前为止的最低买入价
        int maxProfit = 0;        // 最大利润

        for (int price : prices) {
            // 更新最低买入价
            minPrice = min(minPrice, price);

            // 如果今天卖出，能获得的利润
            int profit = price - minPrice;

            // 更新最大利润
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};
*/


/*  
// 贪心 greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {

       int min_price = INT_MAX;
       int max_profit = 0;

       for (int p: prices)
       {
          if (p < min_price)
            min_price = p;
          else
            max_profit = max(max_profit, (p-min_price));
       }

       return max_profit;
    }
};
*/
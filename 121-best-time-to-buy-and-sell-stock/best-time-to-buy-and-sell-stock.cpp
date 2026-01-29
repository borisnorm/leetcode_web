
class Solution {
public:
   
    int maxProfit(vector<int>& prices) {
          int n = prices.size();

          if (n == 0) return 0;
          vector<vector<int>>  dp(n, vector<int>(2, 0));
          //dp[i][j] the max amount money on ith day(0-based) for either hold or not hold stock;
          dp[0][0] = 0;
          dp[0][1] = -prices[0];  // hold stock on first day 

          for (int i = 1; i < n; i++)
          {
             // hold stock
             dp[i][1] = max(dp[i-1][1], -prices[i]);


             // not hold any stock
             dp[i][0] = max(dp[i-1][0],  dp[i-1][1]+prices[i]);
          }

          return dp[n-1][0];
    }
};

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

            // 更新最大利润              //如果今天卖出，能获得的利润
            maxProfit = max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};
*/

/*
//同样是贪心
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

/*
// Time Limit Exceeded
class Solution {
public:
    int maxProfit(vector<int>& prices) {

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
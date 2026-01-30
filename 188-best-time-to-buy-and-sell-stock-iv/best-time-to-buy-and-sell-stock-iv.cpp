class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if (n <= 1)
          return 0;
        
        // n 个大小的 prices 可以完成 n/2次 txn 交易(买 + 卖)
        // over 了 n/2, 就可以使用贪心了
        if (k >= n/2)
        {
            int maxProfit = 0;
            for (int i = 1; i < n; i++)
            {
                if (prices[i] > prices[i-1])
                  maxProfit += prices[i] - prices[i-1];
            }

            return maxProfit;
        }

        vector<vector<int>> dp(n, vector<int>(2*k+1, INT_MIN/2));

        // dp[i][j] the max amount profit on ith day(0-based) either on hold or not hold stock; 
        dp[0][0] = 0;
       // dp[0][1] = -prices[0];
        
        for (int j = 1; j < 2*k; j+=2) 
        {
           dp[0][j] = -prices[0];     //hold
           dp[0][j+1] = 0;   // not hold
        }
        
      

        for (int i = 1; i < n; i++)
        {
            //dp[i][0] = dp[i-1][0];
            dp[i][0] = 0;

            for (int j = 1; j < 2*k; j+=2)
            {
               //dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
               dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] - prices[i]);    //hold

               //dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
               dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j] + prices[i]);  //not hold
            }
        }

        return dp[n-1][2*k];
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if (prices.empty())
           return 0;

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));

        // dp[i][0]  not-hold  --> value after sell 
        // dp[i][1]  hold      --> value after buy  
        for (int i = 0; i < n; i++)
        {
           if (i == 0)
           {
              dp[0][0] = 0;
              dp[0][1] = -prices[0];
              continue;
           }

           dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
           dp[i][1] = max(dp[i-1][1], -prices[i]);
        }

        return dp[n-1][0];
    }
};
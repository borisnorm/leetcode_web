
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 0)
          return 0;
        else if (n == 1)
          return 0;
        else if (n == 2)
          return max(0, prices[1]-prices[0]);
        
        vector<vector<int>> dp(n, vector<int>(5, 0));
        dp[0][0] = 0; // not hold anything
        dp[0][1] = -prices[0]; // hold the 1st stock
        dp[0][2] = 0; // not hold the 1st stock
      //  dp[0][3] = INT_MIN/2; // hold the 2nd stock;
        dp[0][3] = -prices[0]; // hold the 2nd stock;
        dp[0][4] = 0; // not hold the 2nd stock;

        // dp[i][j]: the max amount benefit on the ith day(0-based) either with hold or not hold stock
        for (int i = 1; i < n; i++)
        {
           dp[i][0] = 0;
           dp[i][1] = max(dp[i-1][1], -prices[i]);  //hold
           dp[i][2] = max(dp[i-1][2], dp[i-1][1]+prices[i]);  //not hold
           dp[i][3] = max(dp[i-1][3], dp[i-1][2]-prices[i]);  //hold
           dp[i][4] = max(dp[i-1][4], dp[i-1][3]+prices[i]);  //not hold
        }

        return max({0, dp[n-1][2], dp[n-1][4]});

    }
};

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int buy1  = INT_MIN/2;
        int sell1 = 0;
        int buy2  = INT_MIN/2;
        int sell2 = 0;

        for (int price : prices)
        {
            buy1  = max(buy1, -price);
            sell1 = max(sell1, buy1 + price);
            buy2  = max(buy2, sell1-price);
            sell2 = max(sell2, buy2 + price);
        }

        return sell2;
    }
};

*/
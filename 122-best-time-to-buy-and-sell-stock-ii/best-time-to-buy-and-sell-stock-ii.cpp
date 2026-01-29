
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if (n == 0)
          return 0;
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        //dp[i][j] : the max amount money it can get on ith day(0-based) on either hold or not hold stock
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i++)
        {
           //hold
           dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);

           // not hold
           dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
        }  

        return dp[n-1][0];

    }
};
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // only one share
        // multiple times on the same day.
        // buy =  -price[i] 
        // sell = +prices[i], maybe price[i+1]
        // first buy, then sell to get money  (price[i+1] > price[i])

        int maxProfit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i-1])
              maxProfit += (prices[i] - prices[i-1]);
        }

        return maxProfit;

    }
};
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sum = 0;
        int n = prices.size();
        vector<int> dp(n, 0);

        for (int i = 0 ; i < n; i++)
        {
            //int price_i = price[i];
            //int maxProfit = 0;
           for (int j = i + 1; j < n; j++)
           {
             
              int dp_two_days_before;
              int dp_yesterday;

              if (i-2 < 0)
                dp_two_days_before = INT_MIN;
              else
                dp_two_days_before = dp[i-2];
            
              if (i-1 < 0)
                dp_yesterday = 0;
              else
                dp_yesterday = dp[i-1];

              if (prices[j] > prices[i])
                dp[i] = max(dp_two_days_before, dp_yesterday + prices[j]);
              else
                dp[i] = max(dp_two_days_before, dp_yesterday - prices[j]);

             if (j == n - 1)
               dp[i] = max(dp_two_days_before, dp_yesterday + prices[j]); 
           }
        }

        return dp[n-1];
    }
};
*/
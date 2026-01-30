class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1)
          return 0;
        
        int not_hold = 0;
        int hold = -prices[0];

        for (int i = 1; i < n; i++)
        {
            int pre_hold = hold;
            int pre_not_hold = not_hold;

            hold = max(pre_hold, pre_not_hold-prices[i]);
            not_hold = max(pre_not_hold, pre_hold+prices[i]-fee);
        }

        return not_hold;
    }
};


/*
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1)
          return 0;
        
        int not_hold = 0;
        int hold = -prices[0];
       
        for (int i = 1; i < n; i++)
        {
           int new_notHold = max(not_hold, hold+prices[i]-fee);
           int new_hold = max(hold, not_hold-prices[i]);

           hold = new_hold;
           not_hold = new_notHold;             
        }

        return not_hold;
    }
};

*/


/*
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1)
          return 0;
        
        //dp[i][j] max amount benefit on ith day(0-based) either hold or not hold stock
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;   //not hold
        dp[0][1] = -prices[0];   // hold 
        
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }


        return dp[n-1][0];
    }
};

*/

/*
//错误
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1)
          return 0;
        
        int not_hold = 0;
        int hold = -prices[0];
       
        for (int i = 1; i < n; i++)
        {
           // 更新后的 not_hold被下面 的 hold 个引用了
           not_hold = max(not_hold, hold + prices[i]-fee);
           hold     = max(hold,     not_hold - prices[i]);           
        }

        return not_hold;
    }
};
*/
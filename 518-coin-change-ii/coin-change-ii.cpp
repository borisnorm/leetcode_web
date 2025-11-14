class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
          return 1;

        if (coins.empty() || amount < 0)
          return 0;

        vector<unsigned long long> dp(amount+1, 0);
        dp[0] = 1;

        for (int coin: coins)
        {
           for (int i = coin; i <= amount; i++)
           {
              dp[i] += dp[i-coin];
           }           
        }

        return dp[amount];

    }


};
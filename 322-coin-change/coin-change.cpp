class Solution {
public:

    vector<int> track;
    vector<vector<int>> res;
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
          return -1;

        if (amount == 0)
          return 0;

        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
          for (int coin: coins)
            if (i >= coin && dp[i-coin] != INT_MAX)
              dp[i] = min(dp[i], dp[i-coin] + 1);
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

};
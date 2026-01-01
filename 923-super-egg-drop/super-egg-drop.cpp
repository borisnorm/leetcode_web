class Solution {
public:
    int superEggDrop(int k, int n) {
        // k egss
        // 0 <= f <= n

        int m = 0;

        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

        while(dp[m][k] < n)
        {
           m++;
            for (int egg = 1; egg <= k; egg++)
              
              //dp[m-1][egg-1] 当前层 下 1层 , 碎了
              //dp[m-1][egg]   当前层 上 1层 , 没碎
              // 1 当前层
              dp[m][egg] = dp[m-1][egg-1] + dp[m-1][egg] + 1;
        }

        return m;
    }
};
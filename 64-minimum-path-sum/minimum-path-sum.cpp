class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int m = grid.size();
         if (m <= 0)
           return 0;
         int n = grid[0].size();
         if (n <= 0)
           return 0;

         vector<vector<int>> dp(m, vector<int>(n, 0));
         //dp[0][0] -> dp[n-1][m-1]

         dp[0][0] = grid[0][0];

         for (int i = 0; i < m; i++)
          for (int j = 0; j < n; j++)
          {
            if (i == 0 && j == 0)
             continue;
            //dp[0][1] = grid[0][1] + min(dp[0][0], dp[-1][1]);
            else if (i == 0)
              dp[i][j] = grid[i][j] + min(dp[i][j-1], INT_MAX/2);
            else if (j == 0)
              dp[i][j] = grid[i][j] + min(INT_MAX/2, dp[i-1][j]);
            else
              dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j]);
          }
         return dp[m-1][n-1];

    }
};
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int m = grid.size();
         if (m <= 0)
           return 0;
         int n = grid[0].size();
         if (n <= 0)
           return 0;

         vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX/2));
         //dp[0][0] -> dp[n-1][m-1]

         dp[1][1] = grid[0][0];

         for (int i = 1; i <= m; i++)
          for (int j = 1; j <= n; j++)
          {
            if (i == 1 && j == 1)
             continue;
            dp[i][j] = grid[i-1][j-1] + std::min(dp[i][j-1], dp[i-1][j]);
          }
         return dp[m][n];

    }
};
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int maxN = 2 * n -1;
        
        dp[0][0] = grid[0][0];

        for (int k = 1; k < maxN; k++)
        {
          for (int i = n - 1; i >= 0; i--)
          {
             for (int p = n - 1; p >= 0; p--)
             {
                int j = k - i;
                int q = k - p;

                if (j < 0 || j >= n || q < 0 || q >= n)
                {
                  dp[i][p] = -1;
                  continue;
                }
                
                if (grid[i][j] < 0 || grid[p][q] < 0)
                {
                  dp[i][p] = -1;
                  continue;
                }
                if (i > 0)
                  dp[i][p] = max(dp[i][p], dp[i-1][p]); //donw, right

                if (p > 0)
                  dp[i][p] = max(dp[i][p], dp[i][p-1]);  // right, down
                
                if (i > 0 && p > 0)
                  dp[i][p] = max(dp[i][p], dp[i-1][p-1]);  // down, down
                
                if (dp[i][p] >= 0) // 存在至少一条合法的路径组合能到达这里
                  dp[i][p] = dp[i][p] + grid[i][j] + ((i!=p) ? grid[p][q] : 0);
             }
          }
        }

        return max(0, dp[n-1][n-1]);
    }

    
/*
    int cherryPickup(vector<vector<int>>& grid) {
         int n = grid.size();
         const int NEG_INF  = -1e9;

         vector<vector<vector<int>>> dp(2*n-1, vector<vector<int>>(n, vector<int>(n, NEG_INF)));

         if (grid[0][0] == -1)
           return 0;
        
         dp[0][0][0] = grid[0][0];

         // 1-based k = n -1 + n -1 =  2n-2 ==> 分批 2n-1+1个
         for (int k = 1; k <= (2 * n - 2); k++)
         {
            for (int r1  = max(0, k - (n-1)); r1 <= min(n-1, k); r1++)
            {
               for (int r2 = max(0, k - (n-1)); r2 <= min(n -1, k); r2++)
               {
                  int c1 = k - r1;
                  int c2 = k - r2;
           
                  if (c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
                    continue;
                  
                  if (grid[r1][c1] == -1 || grid[r2][c2]== -1)
                    continue;

                  int best = NEG_INF;
                  best = max(best, dp[k-1][r1][r2]);  // right right;

                  if (r1 > 0)
                     best = max(best, dp[k-1][r1-1][r2]); // down, right

                  if (r2 > 0)
                    best = max(best, dp[k-1][r1][r2-1]); // right, down

                  if (r1 > 0 && r2 >0)
                    best = max(best, dp[k-1][r1-1][r2-1]); // down, down

                  if (best < 0)
                    continue;
                
                  int cherries = best + grid[r1][c1];
                  if (r1 != r2)
                    cherries += grid[r2][c2];
                
                  dp[k][r1][r2] = cherries;

               }
            }
         }

        return max(0, dp[2*n-2][n-1][n-1]);
    }

    */
};
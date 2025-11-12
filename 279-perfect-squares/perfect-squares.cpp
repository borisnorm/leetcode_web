class Solution {
public:
    
    int numSquares(int n) {
        // 1, 4, 9, 16, 25
        // n1 * n1 * n1 * n1 = n * n
        if (n <= 0)
          return 0;

        vector<int> dp(n+1, INT_MAX/2);
        dp[0] = 0; 

        for (int i = 1; i <= n; i++)
        {
           // 错误  for (int j = 1; j*j <= n; j++)
           for (int j = 1; j*j <= i; j++)
           {
              dp[i] = min(dp[i], dp[i-j*j] + 1);
           }
        }

        return dp[n];
    }

    /*
        int numSquares(int n) {
        // 1, 4, 9, 16, 25
        // n1 * n1 * n1 * n1 = n * n
        if (n <= 0)
          return 0;
        
        vector<int> dp(n+1, INT_MAX/2);
        dp[0] = 0;

        for (int i = 1; i * i <= n; i++)
        {
            int s = i * i;
            for (int j = s; j <= n; j++)
            {
               dp[j] = min(dp[j], dp[j-s] + 1);
            }
        }

        return dp[n];
    }
    */

};
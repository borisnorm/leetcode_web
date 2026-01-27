class Solution {
public:

    int integerBreak(int n) {
        
        if (n <= 1)
          return n;

        vector<int> dp(n+1, 0);
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
           int best = 0;
           for (int j = 1; j < i; j++)
           {
              int withoutSplit = j * (i-j);
              int withSplit = j * dp[i-j];

              best = max(best, max(withoutSplit, withSplit));
           }
            dp[i] = best;
        }
        
        return dp[n];
    }
};